#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n;
string s[MAXX];

int main()
{
    _FastIO;

    cin >> n;
    string ans = "Yes";
    char c;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(i){
            if(c != s[i][0]){
                ans = "No";
            }
           for(int j = i - 1; j >= 0; j--){
                if(s[i] == s[j])
                    ans = "No";
           }
        }
        string h = s[i];
        int p = h.size();
        c = h[p - 1];
    }
    cout << ans << endl;
    return 0;
}
