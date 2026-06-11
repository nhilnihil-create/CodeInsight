#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    string S; cin >> S;
    int year = stoi(S.substr(0, 4));
    int month = stoi(S.substr(5, 2));
    int day = stoi(S.substr(8, 2));
    if (year > 2019) {
        cout << "TBD" << endl;
    } else if (year < 2019) {
        cout << "Heisei" << endl;
    } else {
        if (month > 4) {
            cout << "TBD" << endl;
        } else {
            cout << "Heisei" << endl;
        }
    }
    return 0;
}