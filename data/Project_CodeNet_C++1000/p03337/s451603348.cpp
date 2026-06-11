#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    int ans = A + B;

    ans = max(ans, A - B);
    ans = max(ans, A * B);

    cout << ans << endl;
}