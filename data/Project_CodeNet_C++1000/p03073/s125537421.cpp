#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    string S;
    cin>>S;
    int l=sz(S);
    vector<int> color(l);
    rep(i,l){
        color.at(i)=S.at(i)-'0';
    }
    int an=0,ans=0;
    rep(i,l){
        an+=abs(color.at(i)-i%2);
    }
    rep(i,l){
        ans+=abs(color.at(i)-(i+1)%2);
    }
    cout<<min(an,ans)<<endl;
}