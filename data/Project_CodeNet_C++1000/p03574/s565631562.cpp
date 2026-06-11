#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(){
    int H, W;
    int count;

    cin >> H;
    cin >> W;

    char S[H][W];

    rep(i, H)
    {
        cin >> S[i];
    }

    rep(i, H)
    {
        rep(j, W){
            if (S[i][j] == '.'){
                count = 0;
                for (int k = -1; k < 2; k++)
                {
                    if((i + k >= 0) && (i + k <= H - 1)){
                        for (int l = -1; l < 2; l++)
                        {
                            if((j + l >= 0) && (j + l <= W - 1)){
                                if((k == 0) && (l == 0)){
                                }else{
                                    // cout << i + k;
                                    if (S[i + k][j + l] == '#') count++;
                                }
                            }
                        }
                    }
                }

                cout << count;
            }else{
                cout << '#';
            }
        }
        cout << endl;
    }

    return 0;
}