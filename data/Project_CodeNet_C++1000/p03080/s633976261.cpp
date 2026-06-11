#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll amari = 1e9+7;
#define ben(a) a.begin(),a.end()

int main(){
	string s;
	int n;
	cin >> n >> s;
	int r = 0,b = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'R')r++;
		else b++;
	}

	if(b < r)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}