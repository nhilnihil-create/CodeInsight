#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define INF 1000000000000000000
#define all(x) x.begin(), x.end()
#define PI 3.141592653589793

int main() {
    string s;
    cin >> s;
    string key = "keyence";
    rep(i, 7) {
        string head = key.substr(0, i);
        string tail = key.substr(i, key.size() - i);
        string shead = s.substr(0, i);
        string stail = s.substr(s.size() - tail.size(), tail.size());
        if (head == shead && tail == stail) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}