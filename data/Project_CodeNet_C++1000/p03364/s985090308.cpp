#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
#define PI acos(-1.0);

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
	int N; cin >> N;
	vector<vector<char>> s(N,vector<char>(N));
	rep(i,N)rep(j,N) cin >> s[i][j];
	int ans = 0;
	rep(i,N){
		bool ok = true;
		rep(j,N)rep(k,N){
			if(s[j][(k+i)%N] != s[k][(j+i)%N]) ok = false;
		}
		if(ok) ans++;
	}
	ans *= N;
	cout << ans << endl;
}

