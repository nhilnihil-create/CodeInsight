#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	string s, t;
	cin >> s >> t;
	for(int i = 0; i < 3; i++) {
		if(s[i] != t[3-i-1]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}
