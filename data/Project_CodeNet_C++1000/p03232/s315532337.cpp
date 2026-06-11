#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
#define mod 1000000007

long long ruijo(long long x,ll n){
	long long p,ans;
	if(n==0)return 1;
	if(n==1)return x;
	if(n%2){
		p = ruijo(x,n/2);
		ans = (x*p)%mod;
		ans = (ans*p)%mod;
		return ans;
	}else{
		p = ruijo(x,n/2);
		ans = (p*p)%mod;
		return ans;
	}
}

int main(){
    ll n;
    cin >> n;
    ll kai = 1;
    for(ll i=2;i<=n;i++){
        kai *= i;
        kai %= mod;
    }
    vector<ll>a(n);
    rep(i,n)cin >> a[i];
    ll sm = 0;
    for(int i=1;i<=n;i++){
        sm += ruijo(i,mod-2);
        sm %= mod;
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        //cerr << sm << endl;
        ans += sm*a[i]%mod;
        ans %= mod;
        sm += mod-ruijo(n-i,mod-2);
        sm %= mod;
        sm += ruijo(i+2,mod-2);
        sm %= mod;
    }
    cout << ans*kai %mod << endl;
    return 0;
}