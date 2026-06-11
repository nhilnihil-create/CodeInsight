#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string S, T;
    cin >> S >> T;

    if (S == T) {
        cout << "Yes" << endl;
        return 0;
    }
    int N = S.size();
    rep(i,N) {
        S = S.at(N-1) + S;
        S.erase(N);
        if (S == T) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
} 
