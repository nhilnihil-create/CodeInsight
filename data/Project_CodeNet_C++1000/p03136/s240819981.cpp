#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int sum = 0; int max = -1;
	for(int i=0; i<n; i++){
		int side;
		cin >> side;
		if(side>max) max = side;
		sum += side;
	}
	if(sum-2*max>0) cout << "Yes";
	else cout << "No";
	return 0;
}