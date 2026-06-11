#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin >> a.at(i);
	}
	sort(a.begin(), a.end(),greater<int>());

	int x,y;
	x=0;
	y=0;
	for(int j=0;j<N;j++){
		if(j%2==0) x+=a.at(j);
		else y+=a.at(j);
	}
	cout << x-y << endl;
}