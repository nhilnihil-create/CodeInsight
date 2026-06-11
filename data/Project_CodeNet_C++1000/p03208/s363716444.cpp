#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <math.h>

#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> h(n);
	
	for(int i = 0; i < n; i++){
		cin >> h.at(i);
	}
	sort(h.begin(), h.end());
	long long min_diff = LONG_MAX;
	for(int i = 0; i < n-k+1; i++){
		int max_height = h.at(i+k-1);
		int min_height = h.at(i);
		if(max_height - min_height < min_diff) min_diff = max_height - min_height;
	}
	cout << min_diff << endl;;
}