#include <iostream>
#include <cstdio>
using namespace std;

int n, lt, rt, md;
char c[100005];
string re;
int main() {
	cin >> n;
	cout << "0\n";
	fflush(stdout);
	cin >> re;
	c[0] = c[n] = re[0];
	rt = n;
	while(1) {
		md = lt+rt >> 1;
		cout << md << '\n';
		fflush(stdout);
		cin >> re;
		c[md] = re[0];
		if(c[md]=='V') return 0;
		else if((md-lt&1) ^ c[md]==c[lt]) lt = md;
		else rt = md;
	}
	return 0;
}