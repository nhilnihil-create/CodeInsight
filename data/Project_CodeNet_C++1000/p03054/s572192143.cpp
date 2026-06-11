#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W, N, sr, sc;
    cin >> H >> W >> N;
    cin >> sr >> sc;
    string S, T;
    cin >> S;
    cin >> T;
    bool awin = false;
    int bwinl = 1;
    int bwinr = W;
    int bwinu = 1;
    int bwind = H;
    for (int i = N-1; i >= 0; i--) {
        if (T[i] == 'R') bwinl = max(bwinl-1, 1);
        if (T[i] == 'L') bwinr = min(bwinr+1, W);
        if (T[i] == 'U') bwind = min(bwind+1, H);
        if (T[i] == 'D') bwinu = max(bwinu-1, 1);
        if (S[i] == 'R') bwinr--;
        if (S[i] == 'L') bwinl++;
        if (S[i] == 'U') bwinu++;
        if (S[i] == 'D') bwind--;
        if (bwinr < bwinl) awin = true;
        if (bwind < bwinu) awin = true;
    }
    if (!awin && bwinl <= sc && sc <= bwinr && bwinu <= sr && sr <= bwind) cout << "YES" << endl;
    else cout << "NO" << endl;
}