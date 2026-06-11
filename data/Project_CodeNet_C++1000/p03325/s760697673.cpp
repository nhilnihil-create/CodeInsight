		#include<bits/stdc++.h>

		using namespace std;

		int main()
		{ios_base::sync_with_stdio(false);
		    cin.tie(NULL);
		    int n,sum=0;
		    cin >> n;
		    int a[n+1];
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
				while (a[i] % 2 == 0) { a[i] /= 2; sum++; }
			}
			cout << sum << endl;
			return 0;

		}