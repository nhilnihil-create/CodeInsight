#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>
#include<complex>
#include <cassert>

using namespace std;

#define ll long long
#define ld long double
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

const double PI=acos(-1);
const double EPS=1e-9; //うまくいかなかったらゆるめる

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef vector<pii> vp;
typedef vector<vi> vvi;

int gcd(int a, int b){if(b==0) return a;return gcd(b,a%b);}
int lcm(int a, int b){return a/gcd(a,b)*b;}

signed main(void) {
	int n,m;
	cin >> n >> m;
	vvi v(m);
	rep(i,m){
		int k;
		cin >> k;
		v[i] = vi(k);
		rep(j,k)cin >> v[i][j],v[i][j]--;
	}
	vi p(m);
	rep(i,m)cin >> p[i];
	int ans = 0;
	rep(bit, 1<<n){
		bool c = true;
		rep(i,m){
			int cnt = 0;
			rep(j,v[i].size())if(bit & (1<<v[i][j]))cnt++;
			if(cnt%2 != p[i])c = false;
		}
		if(c){
			ans++;
		}
	}
	cout << ans << endl;
}
