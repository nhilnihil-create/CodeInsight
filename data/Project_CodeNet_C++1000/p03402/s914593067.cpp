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
const int N = 100;

char ans[N][N];

int main() {
	int a,b;cin>>a>>b;a--;b--;
	rep(i,50) rep(j,100) ans[i][j]='#';
	rep(i,50) rep(j,100) ans[i+50][j]='.';
	int i=1,j=0;
	while(a>0){
		if(j==99){i+=3;j=0;}
		ans[i+j%2][j]='.';
		a--;j++;
	}
	i=51;j=0;
	while(b>0){
		if(j==99){i+=3;j=0;}
		ans[i+j%2][j]='#';
		b--;j++;
	}
	cout<<100<<' '<<100<<endl;
	rep(i,100){
		rep(j,100) cout<<ans[i][j];
		cout<<endl;
	}
}
