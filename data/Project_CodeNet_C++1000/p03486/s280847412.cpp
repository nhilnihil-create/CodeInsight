#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string s,t;
    cin >> s >> t;
    
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    
    if ( s < t ) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
