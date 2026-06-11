#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, y;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec.at(i);
	}
    int size,count;
	count = 0;
	sort(vec.begin(), vec.end());
	size = 0;
	for (int i = 0; i < N; i++) {
        y = vec.at(i);
		if (size == y) {
    		continue;
    	}
		else {
    		size = y;
        	count++;
    	}
	}
		cout << count << endl;
}