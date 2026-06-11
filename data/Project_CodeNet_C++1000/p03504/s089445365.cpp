#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

int N, C;
int s[100050];
int t[100050];
int c[100050];

bool canRecord(vi& order, int k) {
	vector<pii> a(k);
	rep(i,0,k) {
		a[i] = mp(0,0);
	}
	rep(i,0,N) {
		int idx = order[i];
		int l = s[idx];
		int r = t[idx];
		int x = c[idx];
		bool flag = false;
		rep(j,0,k) {
			if(a[j].S == 0 || a[j].S == x) {
				if(a[j].F <= l) {
					a[j].F = r;
					a[j].S = x;
					flag = true;
				}
			} else {
				if(a[j].F+1 <= l) {
					a[j].F = r;
					a[j].S = x;
					flag = true;
				}
			}

			if(flag) {
				break;
			}
		}
		if(!flag) {
			return false;
		}
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> N >> C;
	rep(i,0,N) {
		cin >> s[i] >> t[i] >> c[i];
	}
	vi order(N);
	rep(i,0,N) {
		order[i] = i;
	}
	sort(all(order), [&](int x, int y) {
		if(s[x] == s[y]) return t[x] < t[y];
		return s[x] < s[y];
	});

	int low = 1; 
	int hig = C;
	while(low < hig) {
		int mid = (low + hig) / 2;
		if(canRecord(order, mid)) {
			hig = mid;
		} else {
			low = mid+1;
		}
	}
	cout << low << '\n';
	return 0;
}
