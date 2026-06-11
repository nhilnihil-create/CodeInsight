#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(int argc, char const *argv[])
{
	int a, b; cin >> a >> b;
	if (a + b == 15)   printf("+\n");
	else if (a * b == 15) printf("*\n");
	else printf("x\n");
	return 0;
}

