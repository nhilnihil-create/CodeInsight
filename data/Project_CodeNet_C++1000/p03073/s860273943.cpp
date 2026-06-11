#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int i, c = 0;
    string s;

    cin >> s;

    int len = s.size();

    for (i = 1; i < len; i++){
        if (s[i] == s[i-1] && s[i] == '0'){
            c++;
            s[i] = '1';
        }


        else if (s[i] == s[i-1] && s[i] == '1'){
            c++;
            s[i] = '0';
        }
        else{
            continue;
        }

    }
    cout << c;

    return 0;

}
