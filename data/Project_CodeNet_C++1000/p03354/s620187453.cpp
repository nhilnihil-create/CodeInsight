#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100000;

int par[N];

void ut_init(){
	rep(i,N) par[i]=i;
}

int ut_root(int x){
	if(par[x]==x) return x;
	else return par[x]=ut_root(par[x]);
}

bool ut_issame(int x,int y){
	return ut_root(x)==ut_root(y);
}

void ut_merge(int x,int y){
	int rx=ut_root(x),ry=ut_root(y);
	if(rx==ry) return;
	par[rx]=ry;
}

int main() {
	int n,m;cin>>n>>m;
	int p[N];rep(i,n) cin>>p[i];
	ut_init();
	rep(i,m){
		int x,y;cin>>x>>y;x--;y--;
		ut_merge(x,y);
	}
	int ans=0;
	rep(i,n) if(ut_issame(p[i]-1,i)) ans++;
	cout<<ans<<endl;
}
