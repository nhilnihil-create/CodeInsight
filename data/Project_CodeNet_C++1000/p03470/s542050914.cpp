#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> d(n);
	for(int i=0; i<n; i++){
		cin >> d.at(i);
	}
	vector<int> vec(110);
	for(int i=0; i<n; i++){
		vec.at(d.at(i))++;
	}
	int num=0;
	for(int i=1; i<=100; i++){
		if(vec.at(i)){
			num++;
		}
	}
	cout << num << endl;
}
