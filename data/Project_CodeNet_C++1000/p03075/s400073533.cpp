#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int  main()
{
	int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
	int k; cin >> k;
	abs(a-e) <= k ? cout << "Yay!"<< endl : cout << ":(" << endl;
	return (0);
}