#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;

ll gcd(ll a,ll b){
    ll M=max(a,b);
    ll m=min(a,b);
    if(m==0){
        return M;
    }
    return gcd(m,M%m);
}


int main(){
	int n;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<ll> left(n);
	vector<ll> right(n);
	left[0]=a[0];
	right[n-1]=a[n-1];
	for(int i=1;i<n;i++){
		left[i]=gcd(left[i-1], a[i]);
	}
	for(int i=n-2;i>=0;i--){
		right[i]=gcd(right[i+1], a[i]);
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		if(i==0){
			ans=right[1];
			continue;
		}
		if(i==n-1){
			ans=max(ans,left[n-2]);
			continue;
		}
		ll l=left[i-1];
		ll r=right[i+1];
		ans=max(ans,gcd(l,r));
	}
	cout<<ans<<endl;
}