#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	ll all = pow(3, n);
	ll ki = 1;
	rep(i, n){
		int in;
		cin >> in;
		if(in%2 == 0) ki *= 2;
	}
	cout << all - ki << endl;
	return 0;
}