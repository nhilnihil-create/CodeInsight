#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int c[500], s[500], f[500]; 
int main() {
	int n;
	cin >> n;
	rep(i,500) f[i] = 1;
	rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
	
	rep(i,n) {
		if (i == n-1) {cout << 0 << endl; continue;}
		int time = s[i] + c[i]; // 今は駅i+1にいる
		if (i == n-2) {cout << time << endl;  continue;}
		
		for (int j = i+1; j < n; j++)
		{
			if (time < s[j]) {
				time = s[j];
			} else if (time % f[j] > 0) {
				int rem = time % f[j];
				time += (f[j]-rem);
			} 
			
			time += c[j];
		}
		cout << time << endl;

	}
	return 0;
}