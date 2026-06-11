#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int A,B;
    cin >> A >> B;

    int coin = max(A, B);

    if(coin == A) {
        A--;
        } else {
            B--;
        }
    coin += max(A, B);
    
    cout << coin << endl;

    return 0;
}