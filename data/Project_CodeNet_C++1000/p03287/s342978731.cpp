#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    llint n, m;
    cin >> n >> m;

    vector<llint> a(n);
    vector<llint> sum(n+1);
    for(llint in=0;in<n;in++) {
        cin >> a.at(in);
        sum.at(in+1) = sum.at(in) + a.at(in);
    }
    
    map<llint, llint> modmap;
    for(int in=0;in<n+1;in++) {
        modmap[sum.at(in)%m]++;
    }
    
    llint ans=0;
    for(auto imap:modmap) {
        llint p = imap.second;
        ans += p*(p-1)/2;
    }

    cout << ans << endl;

    return 0;
}
