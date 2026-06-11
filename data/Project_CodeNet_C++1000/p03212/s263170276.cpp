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

ll N;
ll dfs(ll atama){
    if(atama>N)return 0;
    ll ans=dfs(atama*10+3)+dfs(atama*10+5)+dfs(atama*10+7);
    vector<bool> a(10,false);
    ll now=atama;
    while(now){
        a.at(now%10)=true;
        now/=10;
    }
    if(a.at(3) && a.at(5) && a.at(7))ans++;
    return ans;
}

int main() {
    cin>>N;
    cout<<dfs(0)<<endl;
}