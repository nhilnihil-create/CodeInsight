#include <iostream>
#include <cstdio>
using namespace std;

int n=4, a, v[10];
int main() {
	while(n--) cin >> a, v[a] = 1;
	puts(v[1] && v[9] && v[7] && v[4] ? "YES" : "NO");
	return 0;
}