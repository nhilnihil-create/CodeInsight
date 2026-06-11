#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include <fstream>
#include <time.h>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int MOD = (ll)1000000000 + 7;
ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
const int MAX = 500050;
typedef pair<int, int>P;

int N, Q;
string S;
int k[100];
signed main() {
	cin >> N >> S >> Q;
	REP(i, Q)cin >> k[i];
	REP(i, Q) {
		int K = k[i];
		int l = 0, r = 0;
		int sumD = 0, sumM = 0, sumDM = 0, res = 0;
		if (S[l] == 'D')sumD++;
		if (S[l] == 'M')sumM++;
		while (r < N) {
			if (r - l < K-1) {
				r++;
				if (S[r] == 'D')sumD++;
				if (S[r] == 'M') {
					sumDM += sumD;
					sumM++;
				}
				if (S[r] == 'C') {
					res += sumDM;
				}
			}
			else {
				if (S[l] == 'D') {
					sumDM -= sumM;
					sumD--;
				}
				if (S[l] == 'M') {
					sumM--;
				}
				l++;
				r++;
				if (S[r] == 'D')sumD++;
				if (S[r] == 'M') {
					sumDM += sumD;
					sumM++;
				}
				if (S[r] == 'C') {
					res += sumDM;
				}
			}
		}
		print(res);
	}
}
