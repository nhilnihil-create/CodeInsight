#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    int ans = a - 1;

    if(b >= a) ans++;

    cout << ans << endl;
}