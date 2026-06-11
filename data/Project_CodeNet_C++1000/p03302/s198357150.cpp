#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mem(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;

const int mn=1e5+5;

int a,b;

int main() {
#ifdef LOCAL
	freopen("../1.txt", "r", stdin);
	clock_t cc=clock();
#endif
	cin>>a>>b;
	if (a+b==15) puts("+");
	else if (a*b==15) puts("*");
	else puts("x");
#ifdef LOCAL
	cout<<"time:"<<(double)(clock()-cc)/CLOCKS_PER_SEC;
#endif
	return 0;
}