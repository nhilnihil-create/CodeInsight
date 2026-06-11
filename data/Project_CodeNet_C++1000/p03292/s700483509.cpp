#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    vector<int>vec = {a,b,c};
    sort(vec.begin(), vec.end());

    cout << vec[1] - vec[0] + vec[2] - vec[1] << endl;
}