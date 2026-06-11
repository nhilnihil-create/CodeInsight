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
const int N = 2000;

int A[N];

int main() {
	int n,z,w;cin>>n>>z>>w;
	rep(i,n) cin>>A[i];
	int ans;
	if(n==1) ans=abs(A[0]-w);
	else ans=max(abs(w-A[n-1]),abs(A[n-2]-A[n-1]));
	cout<<ans<<endl;
}
