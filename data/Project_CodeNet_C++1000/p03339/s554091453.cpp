#include <bits/stdc++.h>

using namespace std;


int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> cntE(n+1);
	vector<int> cntW(n+1);
	for (int i = 1; i <= n; i++) {
		cntE[i]=cntE[i-1]+(s[i-1]=='E');
		cntW[i]=cntW[i-1]+(s[i-1]=='W');
	}
	int bestV = n;
	for (int i = 1; i <= n; i++) {
		int tot = cntW[i-1]+cntE[n]-cntE[i];
		bestV = min(bestV, tot);
	}
	cout << bestV << "\n";
}
