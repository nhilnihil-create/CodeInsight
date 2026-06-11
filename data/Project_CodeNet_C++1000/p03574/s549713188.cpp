#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    string S[H];
    for(int i = 0; i < H; i++) cin >> S[i];

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int count = 0;

            if(i != 0 ) {
               if(S[i-1][j] == '#') count++;
            }
            if(i != H-1) {
                if(S[i+1][j] == '#') count++;
            }
            if(j != 0) {
                if(S[i][j-1] == '#') count++;
            }
            if(j != W-1) {
                if(S[i][j+1] == '#') count++;
            }
            if(i != 0 && j != 0) {
                if(S[i-1][j-1] == '#') count++;
            }
            if(i != H-1 && j != 0) {
                if(S[i+1][j-1] == '#') count++;
            }
            if(i != 0 && j != W-1) {
                if(S[i-1][j+1] == '#') count++;
            } 
            if(i != H-1 && j != W-1) {
                if(S[i+1][j+1] == '#') count++;
            }
            if(S[i][j] != '#'){
                string s = to_string(count);
                S[i][j] = s[0];
            }
            
        }
    }

    for (int i = 0; i < H; i++)
    {
        cout << S[i] << endl;
    }
    
}