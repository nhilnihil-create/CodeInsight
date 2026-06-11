#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

const ll MOD = 1e15 + 9;

int main() {
    int N;
    string S;
    cin >> N >> S;
    map<string, ll> m1, m2;
    rep(i, 1 << N) {
        string a = "", b = "", c = "", d = "";
        rep(j, N) {
            if ((i >> j) % 2) {
                a += S[j];
                b += S[2 * N - 1 - j];
            } else  {
                c += S[j];
                d += S[2 * N - 1 - j];
            }
        }
        //cout << i << endl;
        //cout << a << endl;
        //cout << b << endl;
        m1[a + " " + c]++;
        m2[b + " " + d]++;
        //cout << m1[a] << endl;
        //cout << m2[b] << endl;
    }
    ll ans = 0;
    for (auto i = m1.begin(); i != m1.end(); i++) {
        ans += i->second * m2[i->first];
        //cout << i->first << i->second << m2[i->first] << endl;
    }
    cout << ans << endl;
}