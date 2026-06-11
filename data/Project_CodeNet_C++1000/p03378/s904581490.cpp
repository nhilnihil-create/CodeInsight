#include <bits/stdc++.h>
using namespace std;

int M, A, X, N, D, E;
int bil[105], i;

int main () {
    cin >> N >> M >> X;
    for (int i=1;i<=M;i++){
        cin >> bil[i];
    }
    D=0;
    E=0;
    for (int i=1;i<X;i++){
        for (int j=1;j<=M;j++){
            if (i==bil[j]){
                D++;
            }
        }
    }
    for (int i=X+1;i<=N;i++){
        for (int j=1;j<=M;j++){
            if (i==bil[j]){
                E++;
            }
        }
    }
    if (D<E){
        cout << D << endl;
    }else{
        cout << E << endl;
    }
}
