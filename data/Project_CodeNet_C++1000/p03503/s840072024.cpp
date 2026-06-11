#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	int k = pow(2, 10);
	vector<vector<int>> a(n, vector<int>(10));
	vector<vector<int>> c(n, vector<int>(11));
	rep(i, n) rep(j, 10) cin >> a.at(i).at(j);
	rep(i, n) rep(j, 11) cin >> c.at(i).at(j);
	int ma = -2000000000;
	for(int i=1; i<k; i++){
    	bitset<10> b1(i);
		int sum = 0;
		rep(j, n){
			int cou = 0;
			rep(l, 10){
				if(a.at(j).at(l) == 1 && b1.test(l)) cou++;
			}
			sum += c.at(j).at(cou);
		}
		if(ma < sum) ma = sum;
	}
	cout << ma << endl;
	return 0;
}