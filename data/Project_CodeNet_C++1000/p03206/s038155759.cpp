#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

	int D;
	cin >> D;

	cout << "Christmas";

	for(int i = 25; i > D; i--) {
		cout << " Eve";
	}

	cout << endl;
}