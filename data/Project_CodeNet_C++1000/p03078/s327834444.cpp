#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tpl = tuple<int,int,int>;

ll solve() {
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    for ( int i = 0; i < X; i++ ) cin >> A[i];
    for ( int i = 0; i < Y; i++ ) cin >> B[i];
    for ( int i = 0; i < Z; i++ ) cin >> C[i];
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());
    int a, b, c;
    // priority queue reverse order
    auto cmp = [&](tpl& x, tpl& y) { 
        int xa, xb, xc, ya, yb, yc;
        tie(xa,xb,xc) = x;
        tie(ya,yb,yc) = y;
        return A[xa]+B[xb]+C[xc] < A[ya]+B[yb]+C[yc];
    };
    priority_queue<tpl, vector<tpl>, decltype(cmp)> q(cmp);
    vector<ll> ans;
    set<tpl> used;
    q.push(tpl(0,0,0));
    used.insert(tpl(0,0,0));
    for ( int i = 0; i < K; i++ ) {
        tie(a,b,c) = q.top();
        q.pop();
        ans.push_back(A[a]+B[b]+C[c]);
        if ( a+1 < X ) {
            auto t = tpl(a+1,b,c);
            if ( used.count(t) == 0 ) {
                q.push(t);
                used.insert(t);
            }
        }
        if ( b+1 < Y ) {
            auto t = tpl(a,b+1,c);
            if ( used.count(t) == 0 ) {
                q.push(t);
                used.insert(t);
            }
        }
        if ( c+1 < Z ) {
            auto t = tpl(a,b,c+1);
            if ( used.count(t) == 0 ) {
                q.push(t);
                used.insert(t);
            }
        }
    }
    for ( int i = 0; i < ans.size(); i++ ) {
        cout << ans[i] << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}