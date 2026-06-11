#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>

using namespace std;

int main() {
	char S[100001];
	int a, b, c;
	int m1, m0;
	scanf("%s", S);

	a = 0; b = 0; c = 0;
	for (int i = 0; i < strlen(S); i++) {
		if (S[i] == 'a') { a++; }
		if (S[i] == 'b') { b++; }
		if (S[i] == 'c') { c++; }
	}

	m1 = a; m0 = a;
	if (m1 < b) { m1 = b; }
	if (m1 < c) { m1 = c; }

	if (m0 > b) { m0 = b; }
	if (m0 > c) { m0 = c; }
	
	if (m1 - m0 <= 1) { printf("YES\n"); }
	else { printf("NO\n"); }

}