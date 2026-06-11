#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 6006;
const long long mod = 1e9 + 7;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        string s;
        cin >> s;
        int n = s.size();
        bool bad = false;
        if(s[n - 1] == '1'){
                bad = true;
        }
        if(s[0] == '0' || s[n - 2] == '0'){
                bad = true;
        }
        for(int i = 1; i < n; i++){
                if(s[i - 1] != s[n - i - 1]){
                        bad = true;
                }
        }
        if(bad){
                cout << -1 << "\n";
                return 0;
        }

        int x = 2;
        cout << 1 << " " << 2 << "\n";
        for(int i = 2; i < n; i++){
                cout << x << " " << i + 1 << "\n";
                if(s[i - 1] == '1'){
                        x = i + 1;
                }
        }
}
