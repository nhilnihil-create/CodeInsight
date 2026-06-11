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
        for(int right = 0; right < n; right++){
            if(s[right] == 'D'){
                d++;
            }else if(s[right] == 'M'){
                m++;
                dm += d;
            }else if(s[right] == 'C'){
                ans += dm;
            }
            int left = right - (k[i] - 1);
            if(left < 0) continue;
            if(s[left] == 'D'){
                d--;
                dm -= m;
            }else if(s[left] == 'M'){
                m--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}