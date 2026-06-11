#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }


int main() {
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i) cin >> v.at(i);

    map<int, int> mpodd;
    map<int, int> mpeven;
    for(int i = 0; i < n; ++i) {
        if(i % 2 == 0) {
            mpodd[v.at(i)]++;
        }else {
            mpeven[v.at(i)]++;
        }
    }

    int odd1 = 0; int odd2 = 0;
    int oddcnt = 0; int oddcnt2 = 0;
    int even1 = 0; int even2 = 0;
    int evencnt = 0; int evecnt2 = 0;
    for(auto p : mpodd) {
        if(p.second > oddcnt) {
            odd2 = odd1;
            oddcnt2 = oddcnt;
            odd1 = p.first;
            oddcnt = p.second;
        }else if(p.second > oddcnt2) {
            odd2 = p.first;
            oddcnt2 = p.second;
        }
    }
    for(auto p : mpeven) {
        if(p.second > evencnt) {
            even2 = even1;
            evecnt2 = evencnt;
            even1 = p.first;
            evencnt = p.second;
        }else if(p.second > evecnt2) {
            even2 = p.first;
            evecnt2 = p.second;
        }
    }

    int ans = 0;
    if(mpodd.size() == 1 && mpeven.size() == 1) {
        if(odd1 == even1) {
            ans = n - (mpeven[even1]);
        }else {
            ans = 0;
        }
    }else if(mpodd.size() == 1) {
        if(odd1 == even1) {
            ans = n - (mpeven[even2]+oddcnt);
        }else {
            ans = n - (oddcnt+mpeven[even1]);
        }
    }else if(mpeven.size() == 1) {
        if(odd1 == even1) {
            ans = n - (evencnt+mpodd[odd2]);
        }else {
            ans = n - (evencnt+mpodd[odd1]);
        }
    }else {
        if(odd1 == even1) {
            ans = n - max(evencnt+mpodd[odd2], oddcnt+mpeven[even2]);
        }else {
            ans = n - (evencnt+oddcnt);
        }
    }

    cout << ans << endl;
}