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
    string S;
    cin>>S;
    int N=sz(S);
    vector<int> A(N);
    rep(i,N){
        A.at(i)=S.at(i)-'0';
    }
    int ans=10000;
    rep(i,N-2){
        int v=A.at(i)*100+A.at(i+1)*10+A.at(i+2);
        chmin(ans,abs(753-v));
    }
    cout<<ans<<endl;
}