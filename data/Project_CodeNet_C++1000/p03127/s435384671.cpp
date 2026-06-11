#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

ll gcd(ll a,ll b){
	if (a%b==0) return(b);
	else return(gcd(b,a%b));
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

int main(){
    int n;
    cin>>n;

    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll ans=a[0];
    for(int i=1;i<n;i++){
        ans=gcd(ans,a[i]);
    }

    cout<<ans<<endl;
}