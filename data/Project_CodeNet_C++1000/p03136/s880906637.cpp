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
    vector<int> L(N);
    rep(i,N)cin>>L.at(i);
    sort(L.begin(),L.end());
    int sum=0;
    rep(i,N-1){
        sum+=L.at(i);
    }
    if(sum<=L.at(N-1))cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}