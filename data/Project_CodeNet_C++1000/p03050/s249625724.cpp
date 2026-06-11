#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

// 約数の列挙O(√n)
vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i=1LL;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if(i!=n/i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> v=divisor(n);

    ll ans=0;
    for(int i=0;i<v.size();i++){
        ll m=v[i]-1;
        if(m<=0) continue;
        if(n/m == n%m) ans+=m;
    }
    cout<<ans<<endl;
}
