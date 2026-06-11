#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, a, b;

int main() {
	cin >> n >> a >> b;
	if((b - a) % 2) puts("Borys");
	else puts("Alice");
	return 0;	
}