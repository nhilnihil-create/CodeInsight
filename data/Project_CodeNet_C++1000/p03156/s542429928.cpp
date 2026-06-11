#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; (i) < ((int)(n)); ++(i))

int main() {
    int ans = 0;
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> X(3, 0);
    rep(i, N) {
        int p;
        cin >> p;
        if(p <= A)
            X[0]++;
        else if(p <= B)
            X[1]++;
        else
            X[2]++;
    }
    ans = *min_element(X.begin(), X.end());
    cout << ans << endl;
}