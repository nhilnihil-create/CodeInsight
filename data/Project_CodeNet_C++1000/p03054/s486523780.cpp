#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int H, W, N;
int sr, sc;
string S, T;

int main() {
    cin >> H >> W >> N;
    cin >> sr >> sc >> S >> T;
    
    bool f = true;
    int t_r = 0;
    int a_l = 0;
    int t_l = 0;
    int a_r = 0;
    int t_u = 0;
    int a_d = 0;
    int t_d = 0;
    int a_u = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') t_r++;
        if (S[i] == 'L') t_l++;
        if (S[i] == 'U') t_u++;
        if (S[i] == 'D') t_d++;

        if (sc + t_r - a_l > W  || sc - t_l + a_r < 1 ||
            sr - t_u + a_d < 1 || sr + t_d - a_u > H ) {
            f = false;
        }        

        if (T[i] == 'L' && sc + t_r - a_l > 1) a_l++;
        if (T[i] == 'R' && sc - t_l + a_r < W) a_r++;
        if (T[i] == 'D' && sr - t_u + a_d < H) a_d++;
        if (T[i] == 'U' && sr + t_d - a_u > 1) a_u++;
    }

    cout << (f ? "YES" : "NO") << endl;

    return 0;
}
