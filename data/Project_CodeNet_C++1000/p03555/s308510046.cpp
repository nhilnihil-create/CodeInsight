#include <bits/stdc++.h>
using namespace std;

int main(){
	string c, d;
	cin >> c >> d;
	if(c.at(1)!=d.at(1) || c.at(0)!=d.at(2) || c.at(2)!=d.at(0)){
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;
}
