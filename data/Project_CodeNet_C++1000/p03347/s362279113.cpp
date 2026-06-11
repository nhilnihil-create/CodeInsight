///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
const int mx = 2000 * 100 + 5;
int a[mx];
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	if(a[0]){
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	for(int i = n - 1; i >= 0; i--){
		if(a[i] + 1 < a[i + 1]){
			cout << -1 << endl;
			return 0;
		}
		if(a[i] + 1 == a[i + 1])
			ans++;
		else
			ans += a[i + 1];
	}
	cout << ans << endl;
	return 0;
}

