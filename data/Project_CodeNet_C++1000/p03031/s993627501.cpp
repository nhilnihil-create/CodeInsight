#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
int main(){
    ll n,m,sk;
    cin >> n >> m;
    int k;
    vector<ll>p(m);
    vector<vector<int>>s(m);

    rep(i,m){
        cin >> k;
        rep(j,k){
            cin >> sk;
            s[i].push_back(sk-1);
        }
    }
    rep(i,m)cin >> p[i];

    int ans = 0;
    rep(bit,1<<n){
        bool ok = true;
        rep(i,m){
            int count = 0;
            for(int j:s[i]){
                if(bit&1<<j)count++;
            }
            if(count%2!=p[i]){
                ok = false;
                break;
            }
        }
        if(ok)ans++;
    }

    cout << ans;

    return 0;
}