#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, C;
    cin >> N >> C;

    int D[C][C];
    for(int i=0; i<C; i++){
        for(int j=0; j<C; j++){
            cin >> D[i][j];
        }
    }

    int c[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    int b[3][C];
    for(int i=0; i<3; i++){
        for(int j=0; j<C; j++){
            b[i][j] = 0;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int m = (i+j)%3;
            b[m][c[i][j]]++;
        }
    }

    int ans = 1000000005;
    for(int c0=0; c0<C; c0++){
        for(int c1=0; c1<C; c1++){
            for(int c2=0; c2<C; c2++){
                if(c0==c1 || c1==c2 || c0==c2) continue;

                int lc[3];
                lc[0] = c0;
                lc[1] = c1;
                lc[2] = c2;

                int t = 0;
                for(int i=0; i<3; i++){
                    for(int j=0; j<C; j++){
                        t += b[i][j]*D[j][lc[i]];
                    }
                }
                ans = min(ans, t);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
