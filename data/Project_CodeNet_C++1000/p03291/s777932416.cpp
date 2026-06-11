#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;

	long mod = 1000000007;
	vector<vector<long> > dp(s.size()+1, vector<long>(4, 0));

	int n = s.size();
	for(int i=n; i >= 0; i--) {
		for(int j=3; j >= 0; j--) {
			if(i == n) {
				dp.at(i).at(j) = (j == 3) ? 1 : 0;
			}else{
				int m = (s.at(i) == '?') ? 3 : 1;
				string str = "ABC";
				dp.at(i).at(j) = m * dp.at(i+1).at(j);
				if(j < 3 && (m == 3 || s.at(i) == str.at(j)))
					dp.at(i).at(j) += dp.at(i+1).at(j+1);
				dp.at(i).at(j) %= mod;
			}
		}
	}
	cout << dp.at(0).at(0) << endl;
}
