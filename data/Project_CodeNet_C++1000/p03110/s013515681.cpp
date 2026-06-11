#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	double sum = 0;
	rep(i, n){
		double a;
		string s;
		cin >> a >> s;
		if(s == "BTC"){
			a *= 380000;
		}
		sum += a;
	}
	cout  << fixed << setprecision(10) << sum << endl;
	return 0;
}