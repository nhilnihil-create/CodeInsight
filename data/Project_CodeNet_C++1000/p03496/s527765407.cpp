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
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 50;

int a[N];

int main() {
	int n;cin>>n;
	rep(i,n) cin>>a[i];
	int i_min=0,v_min=INF;
	rep(i,n) if(a[i]<v_min) {i_min=i;v_min=a[i];}
	int i_max=0,v_max=-INF;
	rep(i,n) if(a[i]>v_max) {i_max=i;v_max=a[i];}
	if(v_max+v_min>=0) {
		cout<<2*n-2<<endl;
		rep(i,n) if(i!=i_max) cout<<i_max+1<<' '<<i+1<<endl;
		rep(i,n-1) cout<<i+1<<' '<<i+2<<endl;
	}
	else {
		cout<<2*n-2<<endl;
		rep(i,n) if(i!=i_min) cout<<i_min+1<<' '<<i+1<<endl;
		rep(i,n-1) cout<<n-i<<' '<<n-i-1<<endl;
	}
}
