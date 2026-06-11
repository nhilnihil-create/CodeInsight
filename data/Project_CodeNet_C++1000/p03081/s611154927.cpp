#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N,Q;
string s;
vector<char> t,d;

int check(int p) {
    if (p<0) return -1;
    if (p>=N) return 1;
    for (int i=0;i<Q;i++) {
        if (t[i]==s[p]) {
            if (d[i]=='L') {
                p--;
                if (p<0) return -1;
            } else if (d[i]=='R') {
                p++;
                if (p>=N) return 1;
            }
        } 
    }
    return 0;
}

int main() {
    cin >> N >> Q >> s;
    t.resize(Q);
    d.resize(Q);
    for ( int i = 0; i < Q; i++ ) {
        cin >> t[i] >> d[i];
    }
    int l1 = -1, l2 = N, r1 = -1, r2 = N;
    while (l2-l1>1) {
        int p = (l1+l2)/2;
        int c = check(p);
        if (c<0) l1 = p;
        else l2 = p;
    }
    while (r2-r1>1) {
        int p = (r1+r2)/2;
        int c = check(p);
        if (c>0) r2 = p;
        else r1 = p;
    }
    int ans = r1>=l2 ? r1 - l2 + 1 : 0;
    cout << ans << '\n';
    return 0;
}