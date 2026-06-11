#include <bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

const int maxn = 205;

signed main(void){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;
	int l = 1;
	--K;
	while (K--)
		l += 2;
	if (l <= N) cout << "YES";
	else cout << "NO";
}
