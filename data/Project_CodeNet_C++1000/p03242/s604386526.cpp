#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    string sn;
    sn = to_string(N);
    string ans;
    for(int i=0; i<3; i++){
        if (sn[i] == '9'){
            ans += "1";
        }
        else ans += "9";
    }
    cout << ans << endl;
}