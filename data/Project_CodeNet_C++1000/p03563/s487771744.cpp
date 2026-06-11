#include <bits/stdc++.h>
using namespace std;

int main() {
	int ratingNow, ratingFuture, a;
	cin >> ratingNow;
	cin >> ratingFuture;
	a = (ratingFuture * 2) - ratingNow;
	cout << a << endl;
	return 0;
}