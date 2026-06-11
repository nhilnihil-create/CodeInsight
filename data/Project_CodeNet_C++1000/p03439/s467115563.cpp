#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

string categ = "VMF";

int main() {
    cout << fixed << setprecision(10);
    
    int N; cin >> N;

    int l = 0, r = N - 1;
    string s;
    int lt, rt;
    cout << l << endl;
    cin >> s;
    rep(i, 3) {
        if (s[0] == categ[i]) {
            lt = i;
        }
    }
    if (lt == 0) {
        return 0;
    }

    cout << r << endl;
    cin >> s;
    rep(i, 3) {
        if (s[0] == categ[i]) {
            rt = i;
        }
    }
    if (rt == 0) {
        return 0;
    }

    // 一つ目の添え字がその区間が偶数(0)か奇数(1)か、二つ目の添え字が異性(0)か同性(1)か
    vector<vector<int>> has_vac = {
        {1, 0},
        {0, 1}
    };

    rep(i, 18) {
        int c = (l + r) / 2;
        int ct;
        cout << c << endl;
        cin >> s;
        rep(j, 3) {
            if (s[0] == categ[j]) {
                ct = j;
            }
        }
        if (ct == 0) {
            return 0;
        }

        int is_odd = (c - l) % 2;
        int is_same = 0;
        if (lt == ct) {
            is_same = 1;
        }

        if (has_vac[is_odd][is_same]) {
            r = c;
            rt = ct;
        } else {
            l = c;
            lt = ct;
        }
    }
    return 0;
}

/*
3	
0
Male	
1
Female	
2
Vacant	
*/