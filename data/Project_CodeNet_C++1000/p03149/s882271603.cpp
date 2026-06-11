#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int N1, N2, N3, N4;
    cin >> N1 >> N2 >> N3 >> N4;
    vector<int>vec = {N1, N2, N3, N4};
    sort(all(vec));
    vector<int>ans = {1,7,9,4};
    sort(all(ans));
    if (vec==ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}