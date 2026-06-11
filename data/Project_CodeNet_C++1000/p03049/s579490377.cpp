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
#define Pll pair<llint,llint>
#define keta(a)  fixed << setprecision(a)
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
const llint INF = 100000000;

int a[28] = { 0 };
bool v[28];
bool f(int i,int t){
	v[i] = true;
	if (a[i] == t)return 1;
	if (v[a[i]])return 0;
	return f(a[i], t);
}

int main() {
	int n;
	int ans = 0;
	cin >> n;
	hei(string) s(n);
	hei(bool) a(n,false), b(n,false);
	int A=0, B=0, C=0;
	rep(i, 0, n) {
		cin >> s[i];
		if (s[i][0] == 'B') {
			b[i] = 1;
		}

		if (s[i][s[i].size() - 1] == 'A') {
			a[i] = 1;
		}
		rep(j, 0, s[i].size() - 1) {
			if (s[i][j] == 'A' && s[i][j + 1] == 'B')ans++;
		}
	}
	rep(i, 0, n) {
		if (a[i] && b[i])C++;
		else if (a[i])A++;
		else if (b[i])B++;
	}
	if (C) {
		ans += C - 1;
		if (B) {
			B--;
			ans++;
		}
		if (A) {
			A--;
			ans++;
		}
	}
	if (A && B)ans += min(A, B);
	cout << ans << endl;
	return 0;
}
