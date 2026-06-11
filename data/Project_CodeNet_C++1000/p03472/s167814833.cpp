#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n, h;
    cin >> n >> h;

    vector<int> a(n);
    vector<int> b(n);

    int amax = 0;
    for(int in=0;in<n;in++) {
        cin >> a.at(in) >> b.at(in);
        if(amax<a.at(in)) {
            amax = a.at(in);
        }   
    }

    int ans = 0;
    sort(b.begin(), b.end(), greater<int>());
    for(int in=0;in<n;in++) {
        if(b.at(in)>=amax) {
            h -= b.at(in);
            ans++;
            if(h<=0) {
                cout << ans << endl;
                return 0;
            }
        }
    }
    
    ans += h / amax;
    if(h%amax!=0) ans++;

    cout << ans << endl;
    return 0;
}
