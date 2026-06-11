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



int main(){
	llint n, m;
	cin >> n >> m;
	hei(llint) a(n), b(n);
	rep(i, 0, n) {
		cin >> a[i] >> b[i];
	}
	sort(b.begin(), b.end());
	sort(a.begin(), a.end());
	llint x = 0;
	llint ans = 0,y=n-1;
	while (true) {
		if (x >= m)break;
		if (y<0||a[n-1]>=b[y]) {
			ans += ((m - x + a[n - 1]-1) / a[n - 1]);
			x = m;
		}
		else {
			if (a[n - 1] < b[y]) {
				x += b[y];
				ans++;
				y--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}