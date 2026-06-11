#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(int argc, char const *argv[])
{
	int n, h, w; cin >> n >> h >> w;
	cout << (n - h + 1) * (n - w + 1) << endl;
	return 0;
}
