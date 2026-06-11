#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	int foods[m] = {0};
	for(int i=0; i<n; i++){
		int k;
		cin >> k;
		for(int i=0; i<k; i++){
			int food;
			cin >> food;
			foods[food-1]++;
		}
	}
	int count =0;
	for(int i=0; i<m; i++){
		if(foods[i]==n) count++;
	}
	cout << count;
	return 0;
}