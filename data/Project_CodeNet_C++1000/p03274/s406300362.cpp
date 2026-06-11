#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a.at(i);
	int ma = 1000000000;
	rep(i, n-k+1){
		if(a.at(i+k-1) <= 0){
			if(ma > -a.at(i)) ma = -a.at(i);
		}else if(a.at(i) >= 0){
			if(ma > a.at(i+k-1)) ma = a.at(i+k-1);
		}else{
			if(ma > a.at(i+k-1)*2 - a.at(i)) ma = a.at(i+k-1)*2 - a.at(i);
			if(ma > a.at(i+k-1) - a.at(i)*2) ma = a.at(i+k-1) - a.at(i)*2;
		}
//	cout << i+k-1 << endl;
	}
	cout << ma << endl;
	return 0;
}