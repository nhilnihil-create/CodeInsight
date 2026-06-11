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
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	ll l = 2,r = 2;
	for(int i = N-1; i >= 0; i--){
		ll d = (ll)(l+A[i]-1)/A[i]*A[i];
		if(d > r || d < l){
			cout << -1 << endl;
			return 0;
		}
		l = d,r = (ll)r/A[i]*A[i]+A[i]-1;
	}
	cout << l << " " << r << endl;
}

