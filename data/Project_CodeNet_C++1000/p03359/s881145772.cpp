#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
#define LL long long
int main(){
    int a, b;
	cin >> a >> b;
	int res = a;
	if (a > b)res--;
	cout << res << endl;

    return 0;
}