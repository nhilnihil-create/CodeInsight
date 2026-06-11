#include <iostream>
#include <algorithm>

#define INF 250000001

using namespace std;

int main(){
    int N, C;
    cin >> N >> C;
    int D[C][C];
    for(int i=0; i<C; i++){
        for(int j=0; j<C; j++){
            cin >> D[i][j];
        }
    }
    int l[3][C];
    for(int i=0; i<3; i++){
        for(int j=0; j<C; j++) l[i][j] = 0;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int c;
            cin >> c;
            l[(i+j)%3][--c]++;
        }
    }
    int ans = INF;
    for(int i=0; i<C; i++){
        for(int j=0; j<C; j++){
            for(int k=0; k<C; k++){
                int temp = 0;
                if(i==j || j==k || k==i) temp = INF;
                else{
                    for(int m=0; m<C; m++){
                        temp += D[m][i] * l[0][m] + D[m][j] * l[1][m] + D[m][k] * l[2][m];
                    }
                }
                ans = min(ans, temp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}