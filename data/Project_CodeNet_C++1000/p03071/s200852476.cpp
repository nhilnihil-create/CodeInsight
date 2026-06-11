// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

		
	int a, b;
	cin >> a >> b;
	if(a==b) cout << a+b;
	else cout << max(a,b)+max(a,b)-1;


	return 0;
}
