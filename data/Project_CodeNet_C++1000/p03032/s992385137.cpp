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
    int n,k;
    cin >> n >> k;
    deque<ll> v(n);
    rep(i,n) cin >> v[i];
    ll ans = 0;
    rep(i,min(k+1,n+1)){
        rep(j,min(k+1,n+1) - i){
            vector<ll> minu;
            ll now = 0;
            rep(l,i) now += v[l], minu.push_back(v[l]);
            rep(m,j) now += v[n - 1 - m], minu.push_back(v[n - 1  - m]);
            sort(minu.begin(),minu.end());
            rep(l, min( int(minu.size()), k -  i - j )){
                if(minu[l] < 0){
                    now -= minu[l];
                }
            }
            ans = max(now,ans);
        }
    }
    cout << ans << endl;
    return 0;
}