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
    vector<string> S(N);
    rep(i,N)cin>>S.at(i);
    int ans=0;
    rep(i,N){
        rep(j,sz(S.at(i))-1){
            if(S.at(i).at(j)=='A' && S.at(i).at(j+1)=='B')ans++;
        }
    }
    vector<int> num(N);
    rep(i,N){
        if(S.at(i).at(0)=='B')num.at(i)+=10;
        if(S.at(i).at(sz(S.at(i))-1)=='A')num.at(i)+=1;
    }
    int eleven=0,zero=0;
    rep(i,N){
        if(num.at(i)==0)zero++;
        if(num.at(i)==11)eleven++;
    }
    if(eleven+zero==N && eleven>0)ans--;
    int a=0,b=0;
    rep(i,N){
        a+=num.at(i)/10;
        b+=num.at(i)%10;
    }
    cout<<ans+min(a,b)<<endl;
}