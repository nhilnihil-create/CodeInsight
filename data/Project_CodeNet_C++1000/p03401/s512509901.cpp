#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 2e9 + 9;
const ll LINF = 1e18;
using namespace std;

int main(){
	int n;
	int sum=0;
	cin >> n;
	vector<int> a(n+2);
	a.at(0) = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a.at(i);
		sum += abs(a.at(i) - a.at(i - 1));
	}
	sum += abs(a.at(n));
	//cout << sum << endl;
	for (int i = 1; i <= n; i++) {
		int nsum = sum;
		nsum -= abs(a.at(i) - a.at(i - 1));
		nsum -= abs(a.at(i + 1) - a.at(i));
		nsum += abs(a.at(i + 1) - a.at(i - 1));
		cout << nsum << endl;
	}
	return 0;
}
