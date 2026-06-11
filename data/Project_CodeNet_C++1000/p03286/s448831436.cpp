#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	int n;
	cin >> n;
	string s;
	if (n == 0){
		cout << 0 << endl;
		return 0;
	}
	while(n){
		int p = abs(n % (-2));
		if (n < 0 && n % 2 != 0) n = n / (-2) + 1;
		else n /= (-2);
		s += '0' + p;
	}
	int len = s.size();
	for(int i = 0; i < len; i++) cout << s[len - 1 - i];
}
