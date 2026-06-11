#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, x;
	cin >>n >>x;
	vector<int> m(n);
	for(auto& k:m){
		cin >> k;
		x -= k;
	}
	sort(m.begin(),m.end());
	int a = m.at(0);
	int c = x/a;
	cout << n+c << endl;
}
