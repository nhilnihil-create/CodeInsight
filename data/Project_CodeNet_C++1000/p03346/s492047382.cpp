#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n;

int main() {
    cin >> n;
    vector<int> P(n, 0);
    vector<int> pos(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> P.at(i);
        P.at(i)--;
        pos.at(P.at(i)) = i;
    }

    int ans = 0; int cnt = 1;
    for(int i = 0; i < n-1; ++i) {
        if(pos.at(i+1) > pos.at(i)) cnt++;
        else {
            chmax(ans, cnt);
            cnt = 1;
        }
    }
    chmax(ans, cnt);

    cout << n-ans << endl;
}