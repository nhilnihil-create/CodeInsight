#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
#define speed ios::sync_with_stdio(0); cin.tie(0);
int const N = 1e5 + 1;

int main(){
	speed
	int n, h, w;
	cin >> n >> h >> w;
	int ans = (n - h + 1) * (n - w + 1);
	cout << ans << endl;
}
