#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll H,W,cnt=0;
    char c[55][55];
    cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (c[i][j] == '#' && c[i][j - 1] != '#' && c[i - 1][j] != '#' && c[i][j + 1] != '#' && c[i + 1][j] != '#') cnt++;
		}
	}
	if (cnt == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
    return 0;
}