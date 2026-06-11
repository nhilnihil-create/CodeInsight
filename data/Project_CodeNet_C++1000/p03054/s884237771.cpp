#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pii;

int main() {
    int H, W, N; cin >> H >> W >> N;
    int sr, sc; cin >> sr >> sc;
    string S, T; cin >> S >> T;
    
    Pii thor = Pii(0, 0), tver = Pii(0, 0);
    Pii ahor = Pii(0, 0), aver = Pii(0, 0);

    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') thor.first--;
        if (S[i] == 'R') thor.second++;
        if (S[i] == 'U') tver.first--;
        if (S[i] == 'D') tver.second++;

        
        if (thor.first + ahor.second + sc < 1 || W < ahor.first + thor.second + sc) {
            cout << "NO" << endl;
            return 0;
        }
        
        if (tver.first + aver.second + sr < 1 || H < aver.first + tver.second + sr) {
            cout << "NO" << endl;
            return 0;
        }

        if (T[i] == 'L') ahor.first--;
        if (T[i] == 'R') ahor.second++;
        if (T[i] == 'U') aver.first--;
        if (T[i] == 'D') aver.second++;

        if (W < thor.first + ahor.second + sc) ahor.second = W - ahor.first - sc;
        if (ahor.first + thor.second + sc < 1) ahor.first = 1 - sc - thor.second;

        if (H < tver.first + aver.second + sr) aver.second = H - aver.first - sr;
        if (aver.first + tver.second + sr < 1) aver.first = 1 - sr - tver.second;
    }
    cout << "YES" << endl;
    return 0;
}