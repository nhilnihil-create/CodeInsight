#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int MOD = (int)1e9+7;

const int INF = 1e9;
const int N = 105;
int n;
int t[N];
int v[N];
int T = 0;

int main(void) {
	//freopen("in.txt", "r", stdin);
	cin >> n;
	rep(i,0,n) {
		cin >> t[i];
	}
	rep(i,0,n) {
		cin >> v[i];
	}
	rep(i,0,n) {
		t[i] *= 2;
		v[i] *= 2;
		T += t[i];
	}
	T++;
	int maxV[T];
	rep(i,0,T) maxV[i] = INF;
	int l = 0;
	rep(i,0,n) {
		int r = l + t[i];
		rep(j,0,T) {
			if(j >= l && j <= r) {
				maxV[j] = min(maxV[j], v[i]);
			} else if(j < l) {
				maxV[j] = min(maxV[j], l-j+v[i]);
			} else if(j > r) {
				maxV[j] = min(maxV[j], j-r+v[i]);
			}
		}
		l = r;
	}
	rep(i,0,T) {
		maxV[i] = min(maxV[i],i);
		maxV[i] = min(maxV[i],T-1-i);
	}
	double ret = 0;
	rep(i,0,T-1) {
		ret += (double)(maxV[i+1]+maxV[i])/8;
	}
	cout << fixed << setprecision(12) << ret << '\n';
	return 0;
}