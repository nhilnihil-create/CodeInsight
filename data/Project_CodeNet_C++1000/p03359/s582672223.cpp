#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	printf("%d\n", n - 1 + (m >= n));
	return 0;
}