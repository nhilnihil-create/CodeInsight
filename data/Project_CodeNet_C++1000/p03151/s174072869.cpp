//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vi a(n), b(n);
    vi sa(n);
    ll suma=0LL, sumb=0LL;
    rep(i, n) {
        cin >> a[i];
        suma += a[i];
    }
    rep(i, n) {
        cin >> b[i];
        sumb += b[i];
        sa[i] = a[i]-b[i];
    }

    if(sumb > suma) {
        cout << -1 << endl;
        return 0;
    }

    sort(sa.begin(), sa.end());
    if(sa[0] >= 0) {
        cout << 0 << endl;
        return 0;
    }
    deque<int> sad;
    rep(i, n) {
        sad.push_back(sa[i]);
    }
    while(!sad.empty()) {
        
        if(sad.front() + sad.back() > 0) {
            sad.back() = sad.front() + sad.back();
            sad.pop_front();
            if(sad.front() >= 0) {
                sad.pop_back();
                break;
            }
        } else if(sad.front() + sad.back() < 0) {
            sad.front() = sad.front() + sad.back();
            sad.pop_back();
        } else {
            sad.pop_back();
            sad.pop_front();
        }
        
    }

    cout << n-sad.size() << endl;
}