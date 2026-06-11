#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, X;
    cin >> A >> B >> C >> X;

    X /= 50;

    int ans = 0;

    for(int i = 0; i <= A; i++) {
        for(int j = 0; j <= B; j++) {
            int x = X - 10 * i - 2 * j;
            if(x < 0) break;
            if(x <= C) ans++;
        }
    }

    cout << ans << endl;
}