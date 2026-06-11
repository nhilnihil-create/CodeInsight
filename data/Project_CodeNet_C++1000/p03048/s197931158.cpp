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
    int R,G,B,N;
    cin>>R>>G>>B>>N;
    int ans=0;
    for(int i=0;i<=N;i+=R){
        for(int j=0;i+j<=N;j+=G){
            if((N-i-j)%B==0)ans++;
        }
    }
    cout<<ans<<endl;
}