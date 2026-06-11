#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int H, W, N; cin >> H >> W >> N;
    int sr, sc; cin >> sr >> sc;
    string s, t; cin >> s >> t;

    unordered_map<char, int> A, T; bool ok = true;
    REP(i, 0, N) {
        T[s[i]]++;
        if (min(H, sr + A['D']) - T['U'] < 1) ok = false;
        if (max(1, sr - A['U']) + T['D'] > H) ok = false;
        if (min(W, sc + A['R']) - T['L'] < 1) ok = false;
        if (max(1, sc - A['L']) + T['R'] > W) ok = false;
        
        // if (sr - T['U'] < 1) ok = false;
        // if (sr + T['D'] > H) ok = false;
        // if (sc - T['L'] < 1) ok = false;
        // if (sc + T['R'] > W) ok = false;

        if (t[i] == 'U') {
            if (T['D'] > 0) T['D']--;
            else A[t[i]]++;
        } else if (t[i] == 'D') {
            if (T['U'] > 0) T['U']--;
            else A[t[i]]++;
        } else if (t[i] == 'L') {
            if (T['R'] > 0) T['R']--;
            else A[t[i]]++;
        } else {
            if (T['L'] > 0) T['L']--;
            else A[t[i]]++;
        }
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}