#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> c(n);
	rep(i, n) cin >> v.at(i);
	rep(i, n) cin >> c.at(i);

	int sum = 0;
	rep(i, n){
		if(v.at(i) > c.at(i)) sum += v.at(i)-c.at(i);
	}

	cout << sum << endl;
	return 0;
}