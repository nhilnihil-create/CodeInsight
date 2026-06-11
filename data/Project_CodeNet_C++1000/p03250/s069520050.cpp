#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);


    int A, B, C;
    cin >> A >> B >> C;

    int ans = 10 * A + B + C;

    ans = max(ans, 10 * B + C + A);
    ans = max(ans, 10 * C + A + B);

    cout << ans << endl;
}