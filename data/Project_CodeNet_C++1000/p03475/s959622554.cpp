#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind 
#define Pint pair<int,int>
#define keta(a)  fixed << setprecision(a)
constexpr auto INF = 1000000000;
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
llint gcd(llint a, llint b) {
	if (b > a)swap(a, b);
	if (a % b == 0)return b;
	return gcd(b, a % b);
}
llint Tow(int m,int n) {//2のn乗
	if (n == 0)return 1;
	llint x = Tow(m,n / 2);
	x *= x;
	if (n % 2 == 1)x *= m;
	return x;
}
ll max(ll a, ll b) {
	if (a < b)return b;
	else return a;
}
struct edge { int to, cost; };

ll x(ll a) {
	if (a % 2 == 0) {
		ll s = a / 2;
		if (s % 2 == 0)return a;
		return a + 1;
	}
	else {
		ll s = (a+1)/ 2;
		return s % 2;
	}
}

int main() {
	int n;
	cin >> n;
	hei(int) a(n-1), b(n-1), c(n-1);
	rep(i, 0, n-1) {
		cin >> a[i] >> b[i] >> c[i];
		b[i] /= c[i];
	}
	rep(i, 0, n) {
		int ans = 0;
		rep(j, i, n - 1) {
			if (ans <= b[j] * c[j])ans = b[j] * c[j]+a[j];
			else {
				ans = ((ans + c[j] - 1) / c[j]) * c[j] + a[j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}