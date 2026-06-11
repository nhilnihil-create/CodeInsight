#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, num;
	cin >> n;
	vector<int> vec(n);
	for (int i=0; i<n; i++) {
		cin >> vec.at(i);
	}
	sort(vec.begin(), vec.end());
	num = vec.at(n-1)-vec.at(0);
	cout << num << endl;
}
