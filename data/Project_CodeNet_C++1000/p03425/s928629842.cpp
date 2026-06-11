#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int P[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
int Q[10] = {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
int R[10] = {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};
int main() {
    ll N; cin >> N;
    ll D[5] = {0,0,0,0,0};
    for (ll i=0; i<N; ++i){
        string s; cin >> s;
        if (s[0]=='M') D[0]++;
        if (s[0]=='A') D[1]++;        
        if (s[0]=='R') D[2]++;
        if (s[0]=='C') D[3]++;
        if (s[0]=='H') D[4]++;        
    }
    ll res = 0;
    for (ll i=0; i<10; ++i) res += D[P[i]]*D[Q[i]]*D[R[i]];
    cout << res << endl;
    return 0;
}