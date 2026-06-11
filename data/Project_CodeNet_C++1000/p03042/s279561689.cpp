#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;

int main() {
    string s;
    cin >> s;
    int first = stoi(s.substr(0,2));
    int second = stoi(s.substr(2,4));
    auto ok = [&](int x) {
        return (x >= 1 && x <= 12);
    };
    if (ok(first) && ok(second))
        cout << "AMBIGUOUS" << endl;
    else if (ok(first) && !ok(second))
        cout << "MMYY" << endl;
    else if (!ok(first) && ok(second))
        cout << "YYMM" << endl;
    else
        cout << "NA" << endl;
}