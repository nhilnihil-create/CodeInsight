#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

// 約数の列挙O(√n)
vector<ll> enum_divisors(ll n){
    vector<ll> res;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            // 重複しないならばiの相方であるN/iもpush
            if(i!=n/i) res.push_back(n/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}


int main(){
    ll n;
    cin>>n;

    auto ed=enum_divisors(n);

    ll ans=0;
    for(auto e : ed){
        ll m=e-1;
        if(m<=0) continue;
        if(n/m==n%m) ans+=m;
    }

    cout<<ans<<endl;
} 
