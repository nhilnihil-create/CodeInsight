
#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p;//<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };



int main() {
	int q;
	cin >> q;
	vl a(q), b(q);
	rep(i, q) {
		cin >> a[i] >> b[i];
		if (a[i] < b[i]) {
			swap(a[i], b[i]);
		}
		if (a[i] == b[i]) {
			cout << 2*(a[i] - 1)<< endl;
		}
		else {
			ll res = 0;
			res += 2 * (b[i] - 1);
			ll ok = 0, ng = a[i] - b[i] + 1;
			while (ok + 1 < ng) {
				ll mid = (ok + ng) / 2;
				ll b0 = b[i], a0 = b[i] + mid;
				bool flag = true;
				for (int j = max(0LL, mid / 2 - 100); j < min(mid, mid / 2 + 100); j++) {
					if ((b0 + j)*(a0 - j) >= a[i] * b[i]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					ok = mid;
				}
				else {
					ng = mid;
				}
			}
			cout << res + ok << endl;
		}
	}
}