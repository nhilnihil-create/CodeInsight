#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int sgn(int n) {
    if (n>0) return 1;
    else if (n<0) return -1;
    else return 0;
}

int main() {
    int n; cin >> n;
    int a[100000];
    rep(i,n) cin >> a[i];
    int cnt = 0;
    rep(i,n) {
        if (sgn(a[i]) == -1) cnt ++;
    }
    rep(i,n) a[i] = abs(a[i]);
    sort(a, a+n);
    if (cnt%2 == 0) {
        cout << accumulate(a, a+n, lint(0)) << endl;
    }
    else {
        cout << accumulate(a+1, a+n, lint(0)) - a[0] << endl;
    }
    
}