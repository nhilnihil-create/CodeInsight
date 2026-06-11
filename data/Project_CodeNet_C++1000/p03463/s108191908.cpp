#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, a, b;cin >> n >> a >> b;
	cout << (((b-a-1)&1) ? "Alice" : "Borys") << "\n";
 	return 0;
}














