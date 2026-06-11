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
    int n;
    cin >> n;
    vector<int> x(n),y(n),h(n);
    int id = -1;
    int ans1,ans2,ans3;
    rep(i,n){
        cin >> x[i] >> y[i] >> h[i];
        if(h[i] > 0) id = i;
    }
    rep(ix,101){
        int nh;
        int jjy;
        bool ok;
        rep(jy,101){
            jjy = jy;
            ok = 1;
            nh = h[id] + abs(ix - x[id]) + abs(jy - y[id]);
            rep(k,n){
                if(h[k] > 0 && nh - abs(ix - x[k]) - abs(jy - y[k]) != h[k]) ok = 0;
                if(h[k] == 0 && nh - abs(ix - x[k]) - abs(jy - y[k]) > 0) ok = 0;
            }
            if(ok){
                ans1 = ix;
                ans2 = jjy;
                ans3 = nh;
            }
        }
    }
    cout << ans1 << " " << ans2 << " " << ans3 << endl;
    return 0;
}