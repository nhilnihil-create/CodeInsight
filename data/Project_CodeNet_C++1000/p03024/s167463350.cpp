#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int main(){
	cin >> s;
	n = 0;
	for (auto &c: s){
		if (c == 'x') n++;
	}
	if (n <= 7) cout << "YES";
	else cout << "NO";
}