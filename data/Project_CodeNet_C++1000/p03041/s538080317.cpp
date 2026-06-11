#include <iostream>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	string s;
	int n, k;
	cin >> n >> k >> s;
	s[k-1] += ('a'-'A');
	cout << s << '\n';

}