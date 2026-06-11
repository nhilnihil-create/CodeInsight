//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const ll mod=1e9+7;
// const int imax = 100000;

int main(){
	ll n;
	cin >> n;
	ll a[n];
	rep(i,n) cin >> a[i];
	sort(a,a+n);
	int mina;
	int cnt = n;
	while(a[1]!=mina+1){
		mina = a[0];
		for(int i = 1; i < n; i++){
			a[i] %= mina;
			if(a[i]==0){
				cnt--;
				a[i] += mina + 1;
			}
		}
		sort(a,a+n);
		n = cnt;
	}
	printf("%lld\n",a[0]);
	return 0;
}


