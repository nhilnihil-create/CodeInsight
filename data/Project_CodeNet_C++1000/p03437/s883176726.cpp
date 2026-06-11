#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll x, y, i;
int main() {
	cin >> x >> y;
	if(x%y==0) return puts("-1")*0;
	for(i=2; ; i++) {
		if(x*i<0) return puts("-1")*0;
		if(x*i%y) break;
	}
	cout << x*i;
	return 0;
}