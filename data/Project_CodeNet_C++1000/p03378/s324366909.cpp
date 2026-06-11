#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, X;
    cin >> N;
    int M = 0;
    cin >> M >> X;
    vector<int> A(M,0);
    for(int i = 0; i < M; i++) {
    cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    for(int i = 0; i < M; i++) {
        if(A.at(i) > X) {
            cout << min(i, M - i) << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}