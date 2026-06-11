#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    string s;
    cin >> s;
    int n = s.size();

    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }

    vector<int> counts(26, 0);
    for (int i = 0; i < n ; i++)
    {
        counts[s[i] - 97] = i + 1;
    }

    if(n < 26){
        for (int i = 0; i < 26; i++)
        {
            if(counts[i] == 0){
                s += (char) (i + 97);
                break;
            }
        }

        cout << s << endl;
    } else {
        int edge = 0;
        for(int i = n; i > 0; i--){
            if(s[i] > s[i-1]) {
                edge = i;
                break;
            }
        }
        char minchar = 'z'+1;
        for(int i = edge; i < n; i++){
            if(minchar > s[i] && s[i] > s[edge-1]){
                minchar = s[i];
            }
        }

        s[edge - 1] = minchar;
        s.resize(edge);
        cout << s << endl;
    }

    return 0;
}
