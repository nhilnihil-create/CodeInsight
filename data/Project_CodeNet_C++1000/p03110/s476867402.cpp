#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    double ans=0.0;
    rep(i,N){
        double x;
        string u;
        cin>>x>>u;
        if(u=="JPY"){
            ans+=x;
        }
        else{
            ans+=x*380000.0;
        }
    }
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
}