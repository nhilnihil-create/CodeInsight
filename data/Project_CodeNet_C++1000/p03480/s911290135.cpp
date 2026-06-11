#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
template<typename T> inline T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }





string s;
int n;
vector<pair<char, int> > v;

vector<pair<char, int> > runlength(string str) {
    vector<pair<char, int> > ret;
    int cnt = 1;
    int n = sz(str);
    rep3(i, 1, n) {
        if (str[i] == str[i - 1]) {
            cnt++;
        } else {
            ret.eb(make_pair(str[i - 1], cnt));
            cnt = 1;
        }
    }
    ret.eb(make_pair(str[n - 1], cnt));
    return ret;
}





bool check(int x) {
    
    char m = s[x - 1];
    rep3(i, n - x, x - 1) {
        if (s[i] != m) return 0;
    }
    
    return 1;
}

template<typename T>
void binary_search(T ok, T ng) {
    while (abs(ng - ok) > 1) {
        T mid = (ng + ok) / 2;
        // cout << mid << endl;
        (check(mid) ? ok : ng) = mid;
        // cout << ok << " " << ng << endl;
    }
    cout << ok << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    // 二分探索を使おうとしたけどそのあと不可
    // 解説みた
    
    cin >> s;
    n = sz(s);
    // cout << n << endl;
    binary_search(1, n + 1);
    
}
