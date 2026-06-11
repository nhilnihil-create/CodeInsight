#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, tem, ans, num;
	cin >> n >> tem >> ans;
	vector<double> vec(n), ondo(n), copy(n);
	for (int i=0; i<n; i++){
		cin >> vec.at(i);
	}
	for (int i=0; i<n; i++){
		ondo.at(i)=1000*tem-6*vec.at(i)-1000*ans;
		if(ondo.at(i)<ans) ondo.at(i)=-ondo.at(i);
	}
	for (int i=0; i<n; i++){
		copy.at(i) = ondo.at(i);
	}
	sort(copy.begin(), copy.end());
	for (int i=0; i<n; i++){
		if(copy.at(0)==ondo.at(i)) break;
		num ++;
	}
	cout << num+1 << endl;
}
