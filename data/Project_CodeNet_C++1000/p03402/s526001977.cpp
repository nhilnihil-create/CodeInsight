#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

bool Bl[100][100];
int main(){
    int A, B;
    cin >> A >> B;
    int H,W;
    H = W = 100;
    printf("%d %d\n", H, W);

    for(int i = 0; i < H/2; i++){
        REP(j,W){
            Bl[i][j] = true;
        }
    }

    int a = 0;
    int idx = 0;
    while(a < A-1){
        Bl[2*(idx/W)][idx%W] = false;
        idx += 2;
        a++;
    }

    int b = 0;
    idx = 0;
    while(b < B-1){
        Bl[1+H/2+2*(idx/W)][idx%W] = true;
        idx += 2;
        b++;
    }

    REP(i,H){
        REP(j,W){
            if(Bl[i][j])
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
    return 0;
}
