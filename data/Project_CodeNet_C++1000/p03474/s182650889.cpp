#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int a, b;
string s;

int main(void){
	cin >> a >> b >> s;
	for(int i = 0; i < s.size(); i++){
		if((i == a && s[i] != '-') || (i != a && s[i] == '-')){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
