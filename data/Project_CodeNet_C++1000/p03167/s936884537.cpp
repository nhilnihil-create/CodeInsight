#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1e9 + 7;

int main(){
    int h, w;
    cin >> h >> w;
    char A[h][w];
    ll B[h][w];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> A[i][j];
            B[i][j] = 0;
        }
    }

    if(A[0][0] == '#')  cout << 0;
    else {
        B[0][0] = 1;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(A[i][j] == '.'){
                    if(i-1 >= 0){
                        B[i][j] = (B[i][j] + B[i-1][j]) % mod;
                    } if(j-1 >= 0){
                        B[i][j] = (B[i][j] + B[i][j-1]) % mod;
                    }
                }
            }
        }
        cout << (B[h-1][w-1])%mod;
    }

}
