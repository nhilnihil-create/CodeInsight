
#include <bits/stdc++.h>

#define null				 ""
#define all(dat)			 dat.begin(), dat.end()
#define over(msg)			 cout << msg << endl, exit(0);
#define loop(i, to)			 for (int i = 0; i < to; ++i)
#define cont(i, to)			 for (int i = 1; i <= to; ++i)
#define foreach(i, dat)      for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long			 num;

using namespace std;

int n, r, c;

int main() {
	cin >> n >> r >> c;
	cout << (n + 1 - r) * (n + 1 - c) << endl;
}
