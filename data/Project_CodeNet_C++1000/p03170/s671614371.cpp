#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    int K;
    cin >> K;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<bool> winF(K + 1,0);
    winF.at(0) = 0;

    for(int i = 1; i <= K; i++) {
        for(int j = 0; j < N; j++) {
            if(i - A.at(j) < 0) {
                break;
            }
            if(!winF.at(i - A.at(j))) {
                winF.at(i) = 1;
            }
        }
    }
    if(winF.at(K)) {
    cout << "First" << endl;
    } else {
    cout << "Second" << endl;
    }

    return 0;
}
