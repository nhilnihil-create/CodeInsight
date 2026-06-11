#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string S;
    cin >> S;
    int even0 = 0;
    int even1 = 0;
    rep(i,S.size()) {
        if (i % 2 == 0 && S.at(i) == '0') ++even0;
        else if (i % 2 == 1 && S.at(i) == '1') ++even0;
    }
    rep(i,S.size()) {
        if (i % 2 == 0 && S.at(i) == '1') ++even1;
        else if (i % 2 == 1 && S.at(i) == '0') ++even1;
    }
    cout << min(even0, even1) << endl;
}
