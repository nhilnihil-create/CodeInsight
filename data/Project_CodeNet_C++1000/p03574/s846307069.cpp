#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    int H,W;
    cin >> H >> W;
    vector<string> V(H + 2);
    rep(i,H + 2) {
        if (i == 0 || i == H + 1) {
            string s = ".";
            rep(j,W + 1) {
                s += ".";
            }
            V[i] == s;
        }
        else {
            string t = ".";
            string u;
            cin >> u;
            string v = t + u + t;
            V[i] = v;
        }
    }
    rep2(j,1,H + 1) {
        rep2(k,1,W + 1) {
            if (V[j][k] == '.') {
                int count = 0;
                if (V[j][k + 1] == '#') {count++;}
                if (V[j][k - 1] == '#') {count++;}
                if (V[j + 1][k] == '#') {count++;}
                if (V[j - 1][k] == '#') {count++;}
                if (V[j + 1][k + 1] == '#') {count++;}
                if (V[j - 1][k + 1] == '#') {count++;}
                if (V[j + 1][k - 1] == '#') {count++;}
                if (V[j - 1][k - 1] == '#') {count++;}
                cout << count;
            }
            else {cout << '#';}
        }
        cout << endl;
    }
}

