#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
const int M = 39;
int main() {
    int N;
    cin >> N;
    i64 S = (1ll << M) - 1;
    i64 mod = -1;
    vector<string> ans;
    for(int i = 0; i < N; i++) {
        i64 X, Y;
        cin >> X >> Y;
        if(!i) {
            mod = (X + Y + 1) & 1;
        } else {
            if(mod != ((X + Y + 1) & 1)) {
                cout << -1 << endl;
                return 0;
            }
        }
        string w = "";
        if (mod) {
            w = "L";
            X++;
        }
        i64 V = X + Y + S;
        i64 W = X - Y + S;
        for(int i = 0; i < M; i++) {
            int a = (V >> (i + 1)) & 1, b = (W >> (i + 1)) & 1;
            char c;
            if(a && b) { // Right
                c = 'R';
            } else if(a && !b) { // Up
                c = 'U';
            } else if(b && !a) { // Down
                c = 'D';
            } else { // Left
                c = 'L';
            }
            w.push_back(c);
        }
        ans.push_back(w);
    }
    cout << M + mod << endl;
    if(mod) cout << "1";
    for (int i = mod; i < M + mod; i++) {
        cout << (i ? " " : "") << (1ll << (i - mod));
    }
    cout << endl;
    for(auto a : ans) {
        cout << a << endl;
    }
    return 0;
}