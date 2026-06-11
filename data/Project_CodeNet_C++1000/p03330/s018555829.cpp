#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

ll n,C;
ll D[35][35];
ll c[505][505];
ll cost[3][35];

int main(){
    cin>>n>>C;
    for(int i=1;i<=C;i++){
        for(int j=1;j<=C;j++) cin>>D[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>c[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=C;k++){
                cost[(i+j)%3][k]+=D[c[i][j]][k];
            }
        }
    }
    ll ans=INF;
    for(int i=1;i<=C;i++){
        for(int j=1;j<=C;j++){
            for(int k=1;k<=C;k++){
                if(i!=j&&j!=k&&k!=i){
                    chmin(ans,cost[0][i]+cost[1][j]+cost[2][k]);
                }
            }
        }
    }
    cout<<ans<<endl;
}