#include <bits/stdc++.h>
using namespace std;

int main(){
	string n;
	cin >> n;
	bool judge=false;
	if(n.at(0)==n.at(1) && n.at(1)==n.at(2)) judge=true;
	if(n.at(1)==n.at(2) && n.at(2)==n.at(3)) judge=true;
	if(judge) cout << "Yes" << endl;
	else cout << "No" << endl;
}
