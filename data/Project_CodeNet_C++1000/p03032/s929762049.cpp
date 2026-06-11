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
int k(int s) {
	int x = 0;
	while (s) {
		x++;
		s /= 10;
	}
	return x;
}

int main() {
	int n, k;
	int ans = 0;
	cin >> n >> k;
	hei(int) a(n);
	rep(i, 0, n)cin >> a[i];
	rep(i, 0, k+1) {
		rep(j, 0, k - i + 1) {
			if (i + j > n)break;
			hei(int) S;
			int sum = 0;
			rep(I, 0, i) {
				S.push_back(a[I]);
				sum += a[I];
			}
			for (int J = 0; J < j;J++) {
				S.push_back(a[n-1-J]);
				sum += a[n-1-J];
			}
			int z = k - i-j;
			sort(S.begin(), S.end());
			rep(I, 0, S.size()) {
				if (S[I] > 0)break;
				if (I >= z)break;
				sum -= S[I];
			}
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}