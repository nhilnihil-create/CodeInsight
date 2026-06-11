#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define X first
#define Y second

#define cil(a,b) ( ((a)%(b) == 0)?((a)/(b)):((a)/(b)+1) )
#define err(x) cerr << #x << " = " << x << endl;
#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout)
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v, c) for(typeof((c).begin())v=(c).begin();v!=(c).end();++v)
#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout)

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pii> vii;

clock_t start;
void Time(bool timeIt) {
	if (!timeIt) return;
	clock_t end = clock();
	double elapsed_time = ((db)end - (db)start) / (db)CLOCKS_PER_SEC;
	printf("Time elapsed = %0.4lf\n", elapsed_time); 
}

#define LINF (long long)1e18
#define EPS 1e-9
#define INF 1000000007ll
#define SIZE 300010
#define MAX_A 1000010

int LIS(vi vec, int n) {
	set<int> s;
	for (int i = 1 ; i <= n ; ++i) {
		set<int>::iterator it = s.lower_bound(vec[i]);
		if (it != s.end()) s.erase(it);
		s.insert(vec[i]);
	}
	return s.size();
}

int LDS(vi vec, int n) {
	for (int i = 1 ; i <= n ; ++i) vec[i] = -vec[i];
	set<int> s;
	for (int i = 1 ; i <= n ; ++i) {
		set<int>::iterator it = s.lower_bound(vec[i]);
		if (it != s.end()) s.erase(it);
		s.insert(vec[i]);
	}
	return s.size();
}

vi soln(int n, int a, int b) {
	int mn = min(a, b);
	if (a + b > n + 1 || 1ll * a * b < 1ll * n) {
		return vi(); 
	}

	vi ans(n + 2);
	int curr = 1, rem = n, num = 1, A = a, B = b;

	while (rem > 0) {
		if (a + b > rem && a <= rem) {
			int m = num + rem - a;
			for (int i = 0 ; i < a ; ++i) {
				ans[curr++] = m++; 
			}
			for (int i = 1 ; i <= rem - a ; ++i) {
				ans[curr++] = num + rem - a - i;
			}
			break;
		}
		
		for (int i = 1 ; i <= b ; ++i) {
			ans[curr++] = num + b - i;
		}
		--a;
		num = num + b;
		rem -= b;
	}

	return ans;
}

int main() {
	start = clock();

	int n, a, b;
	cin >> n >> a >> b;

	vi ans = soln(n, a, b);
	if (ans.empty()) cout << -1 << endl;
	else {
		for (int i = 1 ; i <= n ; ++i) cout << ans[i] << " "; 
		cout << endl;
	}

	Time(false);
	return 0;
}
