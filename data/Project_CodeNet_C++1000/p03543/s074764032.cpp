			#include<bits/stdc++.h>
			#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
			#define endl "\n"

			using namespace std;
	
		int main() {	
			string x; cin >> x;
			bool ok = 0;
			for (int i = 0; i < (int)x.size() - 2; ++i)
				if (x[i] == x[i + 1] && x[i + 1] == x[i + 2]) ok = 1;
			if (ok) cout << "Yes";
			else cout << "No";

			return 0;

			}
	