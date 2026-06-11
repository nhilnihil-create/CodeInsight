#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main() {
    string s;
    cin >> s;
    bool flag1 = false;
    bool flag2 = false;
    if(s[0] == '0' && s[1] != '0') flag1 = true;
    else if(s[0] == '1' && (s[1] == '0' || s[1] == '1' || s[1] == '2')) flag1 = true;
    if(s[2] == '0' && s[3] != '0') flag2 = true;
    else if(s[2] == '1' && (s[3] == '0' || s[3] == '1' || s[3] == '2')) flag2 = true;
    if(flag1) {
        if(flag2) cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    }
    else if(flag2) cout << "YYMM" << endl;
    else cout << "NA" << endl;
    return 0;
}