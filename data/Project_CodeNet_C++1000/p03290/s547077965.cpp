#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int d,g;
    cin >> d >> g;
    int res = inf;
    vector<int> p(d),c(d);
    rep(i,d) cin >> p[i] >> c[i];
    rep(i, (1<<d)){
        int now = 0;
        int cnt = 0;
        rep(j,d){
            if((i>>j)&1) now += 100*(j+1)*p[j] + c[j], cnt += p[j]; 
        }
        if(now >= g) res = min(res,cnt);
        else{
            for(int j = d-1; j >= 0;j --){
                if((i >> j)&1) continue;
                for(int k = 0;k < p[j]-1; k++){
                    now += 100*(j+1);
                    cnt++;
                    if(now >= g) res = min(res, cnt);
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}