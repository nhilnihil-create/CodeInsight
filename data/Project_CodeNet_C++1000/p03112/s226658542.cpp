#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

lint tikaiRight(vector<lint>& v, lint pos) {
    auto itr = lower_bound(v.begin(), v.end(), pos);
    if (itr == v.end()) return 99999999999;
    return *itr;
}
lint tikaiLeft(vector<lint>& v, lint pos) {
    auto itr = lower_bound(v.begin(), v.end(), pos);
    if (itr == v.begin()) return 99999999999;
    return *--itr;
}
lint tikai(vector<lint>& v, lint pos) {
    auto left = tikaiLeft(v,pos);
    auto right = tikaiRight(v,pos);
    if (abs(pos - left) < abs(pos - right)) return left;
    return right;
}

int main() {
    int a,b,q; cin >> a >> b >> q;
    vector<lint> s(a); rep(i,a) cin >> s[i];
    vector<lint> t(b); rep(i,b) cin >> t[i];
    vector<lint> x(q); rep(i,q) cin >> x[i];
    rep(i, q) {
        lint ans = 999999999999999;
        lint cost = 0;
        lint pos;
        lint next;
        pos = x[i];
        next = tikaiLeft(s,x[i]);
        cost = abs(pos - next);
        pos = next;
        cost += abs(pos - tikai(t, pos));
        ans = min(ans,cost);

        pos = x[i];
        next = tikaiRight(s,x[i]);
        cost = abs(pos - next);
        pos = next;
        cost += abs(pos - tikai(t, pos));
        ans = min(ans,cost);
        
        pos = x[i];
        next = tikaiLeft(t,x[i]);
        cost = abs(pos - next);
        pos = next;
        cost += abs(pos - tikai(s, pos));
        ans = min(ans,cost);

        pos = x[i];
        next = tikaiRight(t,x[i]);
        cost = abs(pos - next);
        pos = next;
        cost += abs(pos - tikai(s, pos));
        ans = min(ans,cost);
        
        cout << ans << endl;
    }

}