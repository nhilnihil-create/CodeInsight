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

int main() {
	int n,k;cin>>n>>k;
	ll ans=0;
	for(int i=k+1;i<=n;i++){
		ans+=n/i*(i-k);
		if(k>0&&n%i>k-1) ans+=n%i-(k-1);
		if(k==0) ans+=n%i;
	}
	cout<<ans<<endl;
}
