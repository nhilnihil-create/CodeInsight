#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n,q;
    string s;
    cin >> n;
    cin >> s;
    cin >> q;
    int k[q];
    rep(i,q){
        cin >> k[i];
    }
    rep(i,q){
        ll d = 0, m = 0, dm = 0;
        ll ans = 0;
        for(int j = 0; j < n; j++){
            if(s[j] == 'D'){
                d++;
            }else if(s[j] == 'M'){
                m++;
                dm += d;
            }else if(s[j] == 'C'){
                ans += dm;
            }
            if(j - (k[i] - 1) < 0) continue;
            if(s[j - (k[i] - 1)] == 'D'){
                d--;
                dm -= m;
            }else if(s[j - (k[i] - 1)] == 'M'){
                m--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}