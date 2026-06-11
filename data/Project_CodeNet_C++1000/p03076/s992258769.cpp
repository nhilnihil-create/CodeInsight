#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<int> V(5);
    vector<int> W(5);
    vector<int> X(5);
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        cin >> V[i];
    }
    for (int j = 0; j < 5; j++) {
        W[j] = V[j]/10 + min(1,V[j]%10);
        ans += W[j]*10;
    }
    for (int k = 0; k < 5; k++) {
        X[k] = (V[k] - 1 )%10 + 1 - 10;
    }
    sort(X.begin(),X.end());
    cout << ans + X[0] << endl;
}