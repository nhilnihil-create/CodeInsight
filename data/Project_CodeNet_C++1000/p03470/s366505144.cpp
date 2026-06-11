#include <bits/stdc++.h>
using namespace std;
int main () {
	int n,d;
	set <int> S;
	cin >> n;
	for(int i=1 ; i<=n ; i++){
		cin >> d;
		if (S.count(d) == 0) S.insert(d);
	}
	cout << S.size() << endl;
}