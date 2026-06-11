#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

int main() {
    int H, W, N;
    cin>>H>>W>>N;
    int sr, sc;
    cin >> sr >> sc;
    string S, T;
    cin >> S >> T;
    int s_x = 0, t_x = 0, s_y = 0, t_y = 0; 
    string ans = "YES";
    REP(i, 0, N){
        if(S[i] == 'L') s_x--;
        if(sc + s_x + t_x <= 0) ans = "NO";
        if(T[i] == 'R' && sc + s_x + t_x < W) t_x++;
    }

    s_x = 0, t_x = 0, s_y = 0, t_y = 0; 
    REP(i, 0, N){
        if(S[i] == 'R') s_x++;
        if(sc + s_x + t_x > W) ans = "NO";
        if(T[i] == 'L' && sc + s_x + t_x  > 1) t_x--;
    }
    
    s_x = 0, t_x = 0, s_y = 0, t_y = 0; 
    REP(i, 0, N){
        if(S[i] == 'U') s_y--;
        if(sr + s_y + t_y <= 0) ans = "NO";
        if(T[i] == 'D' && sr + s_y + t_y < H) t_y++;
    }
    
    s_x = 0, t_x = 0, s_y = 0, t_y = 0; 
    REP(i, 0, N){
        if(S[i] == 'D') s_y++;
        if(sr + s_y + t_y > H) ans = "NO";
        if(T[i] == 'U' && sr + s_y + t_y > 1) t_y--;
    }
    
    cout << ans << endl;     
}