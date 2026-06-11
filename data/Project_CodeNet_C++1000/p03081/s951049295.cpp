#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl

bool ok_left(int cur, int n, int q, string s, vector<char>& t, vector<char>& d) {
    for(int i = 0; i < q; ++i) {
        if(s[cur-1] == t[i]) {
            if(d[i] == 'L') cur--;
            else cur++;
        }
        if(cur == 0) return true;
        if(cur == n+1) return false;
    }
    return false;
}

int find_left(int n, int q, string s, vector<char>& t, vector<char>& d) {
    int l = 0, r = n+1;
    while(r-l > 1) {
        int mid = (l+r)/2;
        if(ok_left(mid, n, q, s, t, d)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

bool ok_right(int cur, int n, int q, string s, vector<char>& t, vector<char>& d) {
    if(cur == n+1) return true;
    for(int i = 0; i < q; ++i) {
        if(s[cur-1] == t[i]) {
            if(d[i] == 'L') cur--;
            else cur++;
        }
        if(cur == 0) return false;
        if(cur == n+1) return true;
    }
    return false;
}

int find_right(int n, int q, string s, vector<char>& t, vector<char>& d) {
    int l = 0, r = n+1;
    while(r-l > 1) {
        int mid = (l+r)/2;
        if(ok_right(mid, n, q, s, t, d)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return n+1-r;
}

int32_t main() {

    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<char> t(q), d(q);
    for(int i = 0; i < q; ++i) cin >> t[i] >> d[i];

    int off_left = find_left(n, q, s, t, d);
    int off_right = find_right(n, q, s, t, d);

    int ans = n-off_left-off_right;

    cout << ans << endl;
    
    return 0;
}
