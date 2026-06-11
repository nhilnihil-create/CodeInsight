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
constexpr auto INF = 100000000000;
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
struct edge { int to, cost; };

int main() {
	int n, k;
	llint ans = INF;
	cin >> n >> k;
	hei(llint) a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	rep(i, 0, n - k + 1) {
		if (a[i] >= 0)ans = min(ans, a[i + k-1]);
		else {
			if (a[i + k - 1] <= 0)ans = min(ans, -1 * a[i]);
			else {
				int x = min(a[k - 1 + i], -1 * a[i]);
				int y = max(a[k - 1 + i], -1 * a[i]);
				if (ans > (x * 2) + y)ans = (x * 2) + y;
			}
		}
	}
	cout << ans << endl;
	return 0;
}