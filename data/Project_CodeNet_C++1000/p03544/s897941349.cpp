#include <iostream>
#include <vector>
#include <algorithm>

#define _GLIBCXX_DEBUG
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back

using namespace std;

int main() {
	int n;
	cin >> n;
	n++;

	vector<ll> lucas(n);
	lucas[0] = 2;
	lucas[1] = 1;
	for (int i = 2; i < n; i++) {
		lucas[i] = lucas[i - 1] + lucas[i - 2];
	}
	cout << lucas[n - 1] << endl;
}