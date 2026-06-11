#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


bool c[26];

int main(){
    string s;
    cin >> s;

    if (s.size() < 26){
        rep(i, s.size()) c[s[i] - 'a'] = 1;
        rep(i, 26){
            if (c[i] == 0) {
                cout << s << char(i + 'a') << endl;
                return 0;
            }
        }
    }
    else {
        int cnt = 0;
        rrep(i, 25) {
            if (s[i] > s[i+1]){
                cnt++;
            }
            else break;
        }
        int idx = 25 - cnt;

        if (idx == 0) {
            cout << -1 << endl;
            return 0;
        }

        for(int i = idx; i < 26; i++) c[s[i] - 'a'] = 1;

        
        
        rep(i, 26) {
            if (c[i] == 1 && i > s[idx-1] - 'a') {
                cout << s.substr(0, idx-1) << char(i + 'a') << endl;
                return 0;
            }
        }

    }

    return 0;
}
