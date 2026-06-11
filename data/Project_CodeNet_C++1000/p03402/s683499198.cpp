#include <bits/stdc++.h>

using namespace std;

#define _for(i,j,N) for(int i = (j); i < (N);i++)

const int maxn = 100;
char G[maxn][maxn];

void print(){
    printf("100 100\n");
    _for(i,0,maxn){
        _for(j,0,maxn){
            printf("%c",G[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A,B;
    scanf("%d %d",&A,&B);
    _for(i,0,maxn){
        _for(j,0,100){
            if(j < 50) G[i][j] = '.';
            else G[i][j] = '#';
        }
    }

    int r = 0,l = 0;
    _for(i,1,B){
        G[r][l] = '#';
        l+=2;
        if(l >= 48){
            l = 0;
            r+=2;
        }
    }

    r = 0,l = 51;
    _for(i,1,A){
        G[r][l] = '.';
        l+=2;
        if(l >= 99){
            l = 51;
            r+=2;
        }
    }

    print();
    return 0;
}