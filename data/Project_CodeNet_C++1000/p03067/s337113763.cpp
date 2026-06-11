#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9 + 7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << endl
#else
#define debug(x)
#endif
int dx[4] ={ 1,0,-1,0 };
int dy[4] ={ 0,1,0,-1 };

int A, B, C;

signed main() {
	cin >> A >> B >> C;
	if(A > B) swap(A, B);
	if(A < C && C < B) cout << "Yes" << endl;
	else cout << "No" << endl;
}