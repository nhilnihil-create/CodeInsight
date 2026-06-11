#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	int f = 0;
	if(s.at(5) == '0'){
		if(s.at(6)-'0' <= 4) f = 1;
	}
	if(f == 0){
		cout << "TBD" << endl;
	}else{
		cout << "Heisei" << endl;
	}
	return 0;
}