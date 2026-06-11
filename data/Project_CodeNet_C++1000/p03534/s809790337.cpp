#include <bits/stdc++.h>

using namespace std;

void fuckit(){
	cout << "NO\n";
	exit(0);
}

int main(){
	string str;
	cin >> str;
	int a = 0;
	int b = 0;
	int c = 0;
	for(auto u : str){
		if(u == 'a') ++a;
		if(u == 'b') ++b;
		if(u == 'c') ++c;
	}
	if(max({a, b, c}) - min({a, b, c}) <= 1) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
