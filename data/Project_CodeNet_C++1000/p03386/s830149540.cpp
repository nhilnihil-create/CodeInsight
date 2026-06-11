#include <bits/stdc++.h>
using namespace std;
int main() {
	int A, B, K;
	cin >> A >> B >> K;
	if (K > B - A) K = B - A + 1;
	set<int> opt;
	for (int i = 0; i < K; i++) opt.insert(A + i);
	for (int i = 0; i < K; i++) opt.insert(B - i);
	vector<int> vec(opt.begin(), opt.end());
	cout << vec.at(0);
	for (int i = 1; i < vec.size(); i++) cout << endl << vec.at(i);
	cout << endl;
}