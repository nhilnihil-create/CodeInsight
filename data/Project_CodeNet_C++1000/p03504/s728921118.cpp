#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;

template <class T>
using lim = numeric_limits<T>;

const int maxT = 10e5;


int tv[31][maxT+2];
int sweep[maxT+2];
int main() {
	ios_base::sync_with_stdio(false) ;
	cin.tie(0);
	
	memset(tv, 0, sizeof tv);
	memset(sweep, 0, sizeof sweep);
	int N, C;
	cin >> N >> C;
	
	//difference array for individual channels
	//merge consecutive shows
	for (int i = 0; i < N; i++){
		int s, t, c;
		cin >> s >> t >> c;
		tv[c][s]++;
		tv[c][t]--;
	}
	
	//combine all channels and line sweep
	for (int i = 1; i <= C; i++){
		for (int j = 0; j < maxT+2; j++){
			if (tv[i][j] < 0) sweep[j+1]+=tv[i][j];
			else sweep[j]+=tv[i][j];
		}
	}
	
	int ans = 0;
	int prefix = 0;
	for (int i = 0; i < maxT+2; i++){
		prefix += sweep[i];
		ans = max(ans,prefix);
	}
	
	cout << ans << endl;
	
}
