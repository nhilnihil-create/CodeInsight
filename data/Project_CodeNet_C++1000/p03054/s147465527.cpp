#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;
int main() {fio;
	int h, w, n, sx, sy;
	cin >> h >> w >> n >> sx >> sy;
	string s, t;
	cin >> s >> t;
	int left = sy, right = sy, up = sx, down = sx;
	for(int i = 0; i < n; i++) {
		left = min(left, w);
		left = max(left, 1);
		right = min(right, w);
		right = max(right, 1);

		up = min(up, h);
		up = max(up, 1);
		down= min(down, h);
		down= max(down, 1);

		if(s[i] == 'L') left--;
		if(s[i] == 'R') right++;
		if(s[i] == 'U') up--;
		if(s[i] == 'D') down++;
		if(left <= 0 || right > w || up <= 0 || down > h) {
			cout << "NO\n";
			return 0;
		}
		if(t[i] == 'L') right--;
		if(t[i] == 'R') left++;
		if(t[i] == 'U') down--;
		if(t[i] == 'D') up++;
	}
	cout << "YES\n";
    return 0;
}