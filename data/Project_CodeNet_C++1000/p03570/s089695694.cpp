#include <bits/stdc++.h>
using namespace std;

#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(int i##_to_ = (t), i = (f); i <= i##_to_; i++)
#define uptil(f, t, i)   for(int i##_to_ = (t), i = (f); i <  i##_to_; i++)
#define downto(f, t, i)  for(int i##_to_ = (t), i = (f); i >= i##_to_; i--)
#define downtil(f, t, i) for(int i##_to_ = (t), i = (f); i >  i##_to_; i--)
typedef long double LD;
#define long long long

#if defined(EBUG) && !defined(ONLINE_JUDGE)
#define debug true
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 2
#define _LIBCPP_DEBUG2 2
#define ln << endl
#else
#define debug false
#define ln << '\n'
#endif
#define tb << '\t'
#define sp << ' '


int pyon[1<<26];

signed main() { // long: 64bit
    if(!debug) {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }

    times(1<<26, i) pyon[i] = INT_MAX-486;
    string S; cin >> S;

    vector<int> d(S.size()+1);
    int z = 0;
    pyon[z] = 0;
    times(S.size(), i) {
        d[i+1] = pyon[z] + 1;
        z ^= 1 << (S[i] - 'a');
        d[i+1] = min(d[i+1], pyon[z] + 1);
        times(26, j) {
            d[i+1] = min(d[i+1], pyon[z ^ (1<<j)] + 1);
        }
        pyon[z] = min(pyon[z], d[i+1]);
        if(debug) cout << z << ":" << pyon[z] sp;
    }

    if(debug) {
        cout ln;
        times(d.size(), i) cout << (i?" ":"") << d[i]; cout ln;
    }

    cout << d[S.size()] ln;

    return 0;
}
