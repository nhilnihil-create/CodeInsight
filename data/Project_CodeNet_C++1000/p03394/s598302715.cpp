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

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	if(n == 3) {
		cout << "2 5 63" << endl;
		return 0;
	}
	int even[8] = {2, 10, 3, 9, 4, 8, 6, 12};
	int odd[8] = {6, 2, 10, 3, 9, 4, 8, 12};
	if(n%2) {
		rep(i,0,n) {
			cout << i/8 * 12 + odd[i%8] << ' ';
		}
	} else {
		rep(i,0,n) {
			cout << i/8 * 12 + even[i%8] << ' ';
		}
	}
	return 0;
}
