#include<iostream>

using namespace std;

int main(void){
    int N, C;
    cin >> N >> C;
    int D[35][35];
    int i, j, k, l;
    for(i=0; i<C; i++){
        for(j=0; j<C; j++){
            cin >> D[i][j];
        }
    }
    int a[3][35];
    for(i=0; i<3; i++){
        for(j=0; j<35; j++){
            a[i][j] = 0;
        }
    }
    int c[510][510];
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            cin >> c[i][j];
            int m = (i+j)%3;
            int n = c[i][j]-1;
            a[m][n]++;
        }
    }
    int res = 500*510*1000;
    int res_c = 0;
    for(i=0; i<C; i++){
        for(j=0; j<C; j++){
            for(k=0; k<C; k++){
                res_c = 0;
                for(l=0; l<C; l++){
                    res_c += D[l][i]*a[0][l] + D[l][j]*a[1][l] +D[l][k]*a[2][l];
                }
                
                if(i == k || j == k || i == j){
                    res_c = 500*510*1000;
                }
                if(res > res_c){
                    res = res_c;
                }
                
            }
        }
    }
    
    /*for(i=0; i<3; i++){
        for(j=0; j<35; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << res << endl;
    return 0;
}