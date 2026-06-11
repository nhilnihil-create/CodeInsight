#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, K;
    cin >> A >> B >> K;

    if(B - A + 1 > K * 2) {
        for(int i = 0; i < K; i++) {
            cout << A + i << endl;
        }
        for(int i = K - 1; i >= 0; i--) {
            cout << B - i << endl;
        }
    } else {
        for(int i = A; i <= B; i++) {
            cout << i << endl;
        }
    }
}