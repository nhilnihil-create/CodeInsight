#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N, M, X, low=0, high=0, a;
    cin >> N >> M >> X;

    vector<int> A(M);
    rep(i, M){
        // cin >> A.at(i);
        cin >> a;
        if (a < X) {
            ++low;
        } else {
            ++high;
        }
    }
    cout << min(low,high) << endl;
    
    return 0;
}
