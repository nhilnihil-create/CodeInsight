#include <iostream>
using namespace std;
int main(void){
    int H, W, N; cin >> H >> W >> N;
    int sh, sw; cin >> sh >> sw;
    string S; cin >> S;
    string T; cin >> T;
    string SS;
    for (int i = 0; i < N; i++) {
        SS.push_back(S[i]);
        SS.push_back('#');
    }
    for (int i = 0; i < N; i++) {
        SS[2*i+1] = T[i];
    }
    
    int lh = 1;
    int uh = H;
    int lw = 1;
    int uw = W;
    
    int ans = 1;
    for (int i = 2*N-1; 0 <= i; i--) {
        if (i%2) {
            if (SS[i] == 'U') {
                uh++;
                uh = min(H, uh);
            }
            if (SS[i] == 'D') {
                lh--;
                lh = max(1, lh);
            }
            if (SS[i] == 'L') {
                uw++;
                uw = min(W, uw);
            }
            if (SS[i] == 'R') {
                lw--;
                lw = max(1, lw);
            }
        } else {
            if (SS[i] == 'U') {
                lh++;
            }
            if (SS[i] == 'D') {
                uh--;
            }
            if (SS[i] == 'L') {
                lw++;
            }
            if (SS[i] == 'R') {
                uw--;
            }
        }
        if (uh - lh < 0 || uw - lw < 0) ans = 0;
    }
    if (!(lw <= sw && sw <= uw && lh <= sh && sh <= uh)) ans = 0;
    
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}
