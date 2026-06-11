/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2020
 */
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(int i = 0; i < n; ++i) cin >> A[i];
    vector<pair<int, int>> cbs(m);
    for(int i = 0; i < m; ++i) {
        int b, c;
        cin >> b >> c;
        cbs[i] = {c, b};
    }
    sort(A.begin(), A.end());
    sort(cbs.rbegin(), cbs.rend());
    int idx = 0;
    long long ans = accumulate(A.begin(), A.end(), 0LL);
    bool done = false;
    for(const auto & cb : cbs) {
        int c = cb.first, b = cb.second;
        // maximum is b
        for(int i = 0; i < b; ++i) {
            if(A[idx] < c) ans += c - A[idx++];
            else {
                done = true;
                break;
            }
            if(idx == n) {
                done = true;
                break;
            }
        }
        if(done) break;
    }
    cout << ans << endl;
    return 0;
    
}

