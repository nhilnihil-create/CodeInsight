#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,ll>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;

ll gcd(ll a,ll b){
    while(b!=0){
        a%=b;
        swap(a,b);
    }
    return a;
}

int main() {
    int N;
    cin>>N;
    vector<ll> A(N);
    rep(i,N)cin>>A.at(i);
    int x=A.at(0);
    rep(i,N){
        x=gcd(x,A.at(i));
    }
    cout<<x<<endl;
}