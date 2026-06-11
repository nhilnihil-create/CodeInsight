#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int M, K;
    cin >> M >> K;
    if (K >= (1 << M)) {
        cout << -1 << endl;
        return 0;
    }
    if (M == 1) {
        if (K == 1) cout << -1 << endl;
        if (K == 0) cout << "0 0 1 1" << endl;
        return 0;
    }
    cout << K;
    for (int i = (1 << M)-1; i >= 0; i--) {
        if (i != K) cout << " " << i;
    }
    cout << " " << K;
    for (int i = 0; i <= (1 << M)-1; i++) {
        if (i != K) cout << " " << i;
    }
    cout << endl;
    return 0;
}