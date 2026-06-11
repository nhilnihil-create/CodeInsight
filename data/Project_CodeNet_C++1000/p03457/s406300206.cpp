#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> t(n+1);
	vector<int> x(n+1);
	vector<int> y(n+1);
	rep(i,n) cin >> t[i+1] >> x[i+1] >> y[i+1];
	int prex = 0;
	int prey = 0;
	bool ok = false;
	rep(i,n){
		int dist = abs(x[i+1] -x[i]) + abs(y[i+1] - y[i]);
		int deltat = abs(t[i+1] - t[i]);
		if(dist > deltat){
			cout << "No" << endl;
			return 0;
		} 
		else{
			if(dist%2 == 1 && deltat%2 == 1) ok = true;
			// if(dist%2 == 0 && deltat%2 == 0) ok = true;
		}
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}