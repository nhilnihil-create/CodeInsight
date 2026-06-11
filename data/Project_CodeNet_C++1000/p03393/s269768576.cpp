#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	string s;
	cin >> s;
	vector<int> vc(26, 0);

	if(s.size() == 26){
		if(s == "zyxwvutsrqponmlkjihgfedcba"){
			cout << -1 << endl;
		}else{
			string temp = s;
			next_permutation(s.begin(), s.end());
			rep(i, s.size()){
				if(temp[i] == s[i]) cout << s[i];
				else{
					cout << s[i] << endl;
					break;
				}
			}
		}
		return 0;
	}

	rep(i, s.size()){
		char c = s[i];
		c -= 'a';
		vc.at(c)++;
	}
	cout << s;
	rep(i, 26){
		if(vc.at(i) == 0){
			char out = 'a' + i;
			cout << out << endl;
			break;
		}
	}
	return 0;
}