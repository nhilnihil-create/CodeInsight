#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;



int main(){
	string num;
	rep(i,4) cin >> num[i];
	int ans; 
	vector<char> op(3);
	rep(bit,(1<<3)){
		bitset<3> tmp(bit);
		ans = num[0]-'0';
		rep(i,3){
			if (tmp.test(i)){
				ans += num[i+1]-'0';
				op[i] = '+';
			}
			else {
				ans -= num[i+1]-'0';
				op[i] = '-';
			}
		}
		if (ans == 7) {
			cout << num[0] << op[0] << num[1] << op[1] << num[2] << op[2] << num[3] << "=7" << endl;
			return 0;
		}
	}



}


