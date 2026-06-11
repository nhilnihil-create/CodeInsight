#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
set<int> S;
 
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        S.insert(a);
    }
    auto it = S.end();
    it--;
    int mid = *it / 2;
    int lo = -1, hi = -1, ans = 0;
    if(S.count(mid)) ans = mid;
    else {
        S.insert(mid);
        auto pos = S.find(mid);
        if(pos != S.begin()) {
            pos--;
            lo = *pos;
            if(lo == *it) lo = -1;
            pos++;
        }
        if(pos != it) {
            pos++;
            hi = *pos;
            if(hi == *it) hi = -1;
        }
        if(lo != -1 && hi == -1) {
            ans = lo;
        }
        else if(lo == -1 && hi != -1) {
            ans = hi;
        }
        else {
            if(mid - lo < hi - mid) {
                ans = lo;
            }
            else ans = hi;
        }
    }
    cout << *it << " " << ans << endl;
}