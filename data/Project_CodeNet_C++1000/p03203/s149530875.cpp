#include <bits/stdc++.h>
using namespace std;
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define COUNT(V,X) upper_bound((V).begin(),(V).end(),X)-lower_bound((V).begin(),(V).end(),X)
#define debug(x) cerr<<#x<<':'<<x<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto xXx:v)cerr<<xXx<<' ';cerr<<endl;
#define INF 1000000007
#define LINF 1000000000000000007
#define int long long
#define Yes(X) if(X){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define YES(X) if(X){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
typedef long long ll;
typedef long double ld;
long long dx[] = {1,0,-1,0};
long long dy[] = {0,1,0,-1};
long long dx8[] = {1,1,0,-1,-1,-1,0,1};
long long dy8[] = {0,1,1,1,0,-1,-1,-1};
long long dx9[] = {1,1,0,-1,-1,-1,0,1,0};
long long dy9[] = {0,1,1,1,0,-1,-1,-1,0};

signed main(){
    ll H,W,N;
    cin >> H >> W >> N;
    ll ans = H;
    vector<pair<ll,ll>> v(N);
    FOR(i,0,N)cin >> v[i].first >> v[i].second;
    sort(ALL(v));
    ll MIN[H+1];
    FOR(i,0,H+1)MIN[i] = LINF;
    MIN[0] = 0;
    FOR(i,0,N)MIN[v[i].first] = min(MIN[v[i].first],v[i].second-1);
    FOR(i,1,H+1)MIN[i] = min(MIN[i],MIN[i-1]+1);
    FOR(i,0,N){
        ll X = v[i].first-1,Y = v[i].second;
        if(MIN[X] >= Y){
            ans = min(ans,X);
        }
    }
    cout << ans << endl;
}