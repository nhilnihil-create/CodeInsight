#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=1005;
const ll INF=1LL<<60;

ll dp[MAX][MAX*20];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<ll,pair<ll,ll>>> S(N);
    for(int i=0;i<N;i++){
        ll a,b,c;cin>>a>>b>>c;
        S[i]=mp(a+b,mp(a,c));
    }
    sort(all(S));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=20000;j++){
            chmax(dp[i+1][j],dp[i][j]);
            if(j<=S[i].fi-S[i].se.fi){
                chmax(dp[i+1][j+S[i].se.fi],dp[i][j]+S[i].se.se);
            }
        }
        for(int j=1;j<=20000;j++) chmax(dp[i+1][j],dp[i+1][j-1]);
    }
    
    cout<<dp[N][20000]<<endl;
}

