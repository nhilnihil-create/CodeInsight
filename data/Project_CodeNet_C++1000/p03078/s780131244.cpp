#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    int x,y,z,k; cin >> x >> y >> z >> k;
    lint a[1000], b[1000], c[1000];

    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    priority_queue<lint, vector<lint>, less<lint>> hq;
    rep(i,x) {
        rep(j,y) {
            hq.push(a[i] + b[j]);
        }
    }
    lint d[3000];
    rep(i,min(k, x*y)) {
        d[i] = hq.top();
        hq.pop();
    }
    priority_queue<lint, vector<lint>, less<lint>> hq2;
    rep(i,min(k, x*y)) {
        rep(j,z) {
            hq2.push(d[i] + c[j]);
        }
    }
    rep(i,k) {
        cout << hq2.top() << endl;
        hq2.pop();
    }
}