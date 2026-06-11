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

ll Xor(ll x){
    if(x%2==0){
        return Xor(x-1)^x;
    }
    x++;
    x/=2;
    if(x%2==0)return 0;
    else return 1;
}

int main() {
    ll A,B;
    cin>>A>>B;
    ll ans=Xor(B);
    if(A==0){cout<<ans<<endl;}
    else{
        ans=ans^Xor(A-1);
        cout<<ans<<endl;
    }
}