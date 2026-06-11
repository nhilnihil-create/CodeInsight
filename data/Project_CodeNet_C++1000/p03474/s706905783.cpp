#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a,b;
	string s;
	cin >> a >> b >> s;
	int len = s.size();
	rep(i,len){
		if(i == a){
			if(s[i] != '-'){
				cout << "No" << endl;
				return 0;
			}
		}else{
			if(s[i] != '0' && s[i] != '1' && s[i] != '2' &&s[i] != '3' &&s[i] != '4' &&s[i] != '5' &&s[i] != '6' &&s[i] != '7' &&s[i] != '8' &&s[i] != '9'){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}