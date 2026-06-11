#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;



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