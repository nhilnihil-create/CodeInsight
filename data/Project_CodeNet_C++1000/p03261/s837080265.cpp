#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    bool check = 1;
    
    for(int i = 0; i < N - 1; i++) {
        if(A.at(i).at(A.at(i).size() - 1) != A.at(i + 1).at(0)) {
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(A.at(i) == A.at(j)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}