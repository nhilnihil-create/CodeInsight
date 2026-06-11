//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    ll n;
    cin >> n;


    vi a;
    int j = 1;
    while(n) {
        if(n%(1LL<<j)) {
            a.push_back(1);
            --j;
            if(j&1) {
                n += 1LL<<j;
            } else {
                n -= 1LL<<j;
            }
            ++j;
        } else {
            a.push_back(0);
        }
        ++j;
    }

    if(a.empty()) {
        cout << 0 << endl;
    } else {
        rep(i, a.size()) {
            cout << a[a.size()-1-i];
        }
        cout << '\n';
    }
}