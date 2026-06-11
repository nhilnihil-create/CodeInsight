#include <iostream>
using namespace std;

int n=3, x, y, cnt, c[5];
int main() {
	while(n--) {
		cin>> x>> y;
		c[x]++, c[y]++;
	}
	for(int i=1; i<=4; i++) if(c[i]%2) cnt++;
	cout<< (cnt==2? "YES": "NO");
	return 0;
}