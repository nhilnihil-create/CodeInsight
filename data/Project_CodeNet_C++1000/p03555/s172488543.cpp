#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char a[10], b[10];
int main(){
	scanf("%s%s", a + 1, b + 1);
	for(int i = 1; i <= 3; ++i) if(a[i] != b[3 - i + 1]) return puts("NO") & 0;
	puts("YES");
	return 0;
} 