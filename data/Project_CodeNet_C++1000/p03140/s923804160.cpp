#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, ans;
string a, b, c, d="...";
int main() {
	int i;
	cin >> n >> a >> b >> c;
	for(i=0; a[i]; i++) {
		d[0] = a[i];
		d[1] = b[i];
		d[2] = c[i];
		sort(d.begin(), d.end());
		if(d[0]!=d[1] && d[1]!=d[2]) ans += 2;
		else if(d[0]==d[1] && d[1]!=d[2]) ans++;
		else if(d[0]!=d[1] && d[1]==d[2]) ans++;
	}
	cout << ans;
	return 0;
}