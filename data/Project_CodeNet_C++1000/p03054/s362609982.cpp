#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define ALL(v) (v).begin(),(v).end()
const ll MOD = 1e9 + 7;
 
int main() {
	int H, W, N;
	cin >> H >> W >> N;
	int sr, sc;
	cin >> sr >> sc;
	sr--; sc--;
	string S, T;
	cin >> S >> T;
	int l = 0, r = W - 1;
	if (S[N - 1] == 'L') l++;
	else if (S[N - 1] == 'R') r--;
	bool ok = 1;
	for (int i = N - 2; i >= 0; i--) {
		if (T[i] == 'L') r = min(r + 1, W - 1);
		else if (T[i] == 'R') l = max(l - 1, 0);
		if (S[i] == 'L') l++;
		else if (S[i] == 'R') r--;
		if (l > r) {
			ok = 0;
			break;
		}
	}
	if (l > sc || r < sc) ok = 0;
	l = 0, r = H - 1;
	if (S[N - 1] == 'U') l++;
	else if (S[N - 1] == 'D') r--;
	for (int i = N - 2; i >= 0; i--) {
		if (T[i] == 'U') r = min(r + 1, H - 1);
		else if (T[i] == 'D') l = max(l - 1, 0);
		if (S[i] == 'U') l++;
		else if (S[i] == 'D') r--;
		if (l > r) {
			ok = 0;
			break;
		}
	}
	if (l > sr || r < sr) ok = 0;
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}