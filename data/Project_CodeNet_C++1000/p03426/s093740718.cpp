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
#define rep(i,a,n) for(llint i=(a);i<(n);i++)
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
const ll mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
const ll INF = 1000000000;



int main() {
	int h, w, d;
	cin >> h >> w >> d;
	hei(int) x(h * w+1), y(h * w+1);
	rep(i, 0, h) {
		rep(j, 0, w) {
			int number;
			cin >> number;
			x[number] = i;
			y[number] = j;
		}
	}
	whei(int) dist(d, hei(int)(2+(h*w)/d,0));
	for (int i = 0; i < d; i++) {
		for (int j = 1; i+j*d <= h * w; j++) {
			int v = i + j * d;
			dist[i][j] = dist[i][j - 1] + abs(x[v] - x[v-d]) + abs(y[v] - y[v-d]);
		}
	}
	
	int q;
	cin >> q;
	hei(int) ans(q,0);
	rep(i, 0, q) {
		int l, r;
		cin >> l >> r;
		ans[i] = dist[r % d][r / d] - dist[l % d][l / d];
	}
	rep(i,0,q)cout << ans[i] << "\n";
    return 0;
}