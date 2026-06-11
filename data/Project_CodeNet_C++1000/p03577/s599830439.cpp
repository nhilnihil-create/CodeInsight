#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#define re register
#define maxn 100010
#define FOR(i, l, r) for(re int i = l; i <= r; ++i)
using namespace std;

int n, m , c, r, t, x, y, z;
char s[maxn];

int main() {
	scanf("%s", &s);
	n = strlen(s);
    FOR(i, 0, n-9)
      cout << s[i];
}