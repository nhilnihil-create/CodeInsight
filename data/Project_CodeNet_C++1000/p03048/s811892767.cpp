#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(int i=0; i<n; i++)
#define rep(i,start,n) for(int i=start; i<n; i++)

signed main(){
    fast;  

    int R, G, B, N;
	cin >> R >> G >> B >> N;
	int ans = 0;
	
	for (int i = 0; i <= 3000; i++)
		for (int j = 0; j <= 3000; j++) {
			int v = i * R + j * G;
			if (N >= v && (N - v) % B == 0) ans++;
		}
	cout << ans << endl;
    return 0;
}
