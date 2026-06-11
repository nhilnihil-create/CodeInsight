#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	bool reved = false;
	int n;
	cin >> n;
	vector<int> a(n);
	
	vector<pair<int,int>> ans;
	
	int Max = -1, pos;
	
	for(int i = 0; n > i; i++){
		cin >> a[i];
		if(abs(a[i]) > Max){
			Max = abs(a[i]);
			pos = i;
		}
	}
	
	if(a[pos] < 0){
		reverse(a.begin(), a.end());
		reved = true;
		for(int i = 0;n > i; i++)
			a[i] *= -1;
		pos = n - pos - 1;
	}
	
	ans.push_back({pos, 0});
	ans.push_back({pos, 0});
	
	for(int i = 0;n - 1 > i; i++){
		ans.push_back({i, i + 1});
		ans.push_back({i, i + 1});
	}
	
	cout << ans.size() << endl;
	for(auto& b : ans){
		if(reved){
			b.first = n - b.first - 1;
			b.second = n - b.second - 1;
		}
		
		cout << b.first + 1 << " " << b.second + 1<< endl;
	}
	
	
	return 0;
}