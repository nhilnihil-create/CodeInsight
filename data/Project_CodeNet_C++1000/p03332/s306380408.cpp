#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const int N = 3e5+6;
const int M = 998244353;
const int inf = 1e9;
ll iv[N],f1[N],f2[N];
ll nck(int n, int k) {
	return f1[n]*f2[k]%M*f2[n-k]%M;
}
void solve(){
    iv[1]=1;
    for(int i=2; i<N; ++i)
		iv[i]=M-M/i*iv[M%i]%M;
	f1[0]=f2[0]=1;
	for(int i=1; i<N; ++i) {
		f1[i]=f1[i-1]*i%M;
		f2[i]=f2[i-1]*iv[i]%M;
	}
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    ll ans = 0;
    for(ll i=0;i<=n;i++){
        ll kk = k-i*a;
        if(kk<0)continue;
        if(kk%b)continue;
        int j = kk/b;
        if(j>n)continue;
        ans+=nck(n,i)*nck(n,j);
        ans%=M;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
