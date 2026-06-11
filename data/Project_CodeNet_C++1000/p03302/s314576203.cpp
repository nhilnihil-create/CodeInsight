#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>


using namespace std;
#define INF 0x3f3f3f3f3f
#define ll long long
#define pr(x) (cerr << #x << ' ' << x << ' ')
#define prln(x) (cerr << #x << ' ' << x << endl)


int main()
{
	#ifdef LOCAL
		freopen("in.txt", "r", stdin);
	#endif // LOCAL
	int a, b;
	scanf("%d %d", &a, &b);
	if (a * b == 15) {
		puts("*");
	}else if (a + b ==  15) {
		puts("+");
	}else {
		puts("x");
	}
	return 0;
}