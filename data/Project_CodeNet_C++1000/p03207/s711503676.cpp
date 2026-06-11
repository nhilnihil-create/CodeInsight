#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
	int N; 
	cin >> N;
	
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += v[i];
	}
	
	int big = v[0];
	for (int i = 0; i < N; i++) {
		big = max(big,v[i]);
	}
	
	cout << sum - big/2 << endl;
	
	return 0;
}