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

int p(int X){
    return (X-1)%10;
}

int main() {
    vector<int> A(5);
    rep(i,5){cin>>A.at(i);}
    vector<int> a(5);
    rep(i,5){
        a.at(i)=p(A.at(i));
    }
    sort(a.begin(),a.end());
    int s=a.at(0)+1;
    s=10-s;
    int t=0;
    rep(i,5){
        t+=A.at(i);
        t+=9;
        t/=10;
        t*=10;
    }
    cout<<t-s<<endl;
}