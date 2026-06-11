#include <stdio.h>
#include <cmath>

int main(){

    char s[8003] = {};
    int x,y;
    int gx[8000] ,gy[8000];
    bool dx[8000][8000] ,dy[8000][8000]; //DP!!!!!
    scanf("%s\n", &s);
    scanf("%d %d", &x, &y);

    int i = 0;
    while( s[i] == 'F'){
        i++;
    }
    x = x-i;
    i++;

    x = std::abs(x);
    y = std::abs(y);

    int j = 0;
    int ix = 0;
    int iy = 0;
    bool yoko = false;
    while( s[i] != 0){
        if( s[i] == 'T'){
            if(yoko) gx[ix++] = j;
            else gy[iy++] = j;
            yoko = !yoko;
            i++;
            j = 0;
        }else{
            i++;
            j++;
        }
    }
    if(yoko) gx[ix++] = j;
    else gy[iy++] = j;
    yoko = !yoko;

    dx[0][0] = true;
    dy[0][0] = true;
    for (int k = 1; k <= iy; k++){
        for (int l = 0; l < 8000; l++){
            if(dx[k-1][l]){
                if(l+gx[k-1] < 8001)   dx[k][l+gx[k-1]] = true;
                if(l-gx[k-1] > -1)     dx[k][l-gx[k-1]] = true;
            }
            if(dy[k-1][l]){
                if(l+gy[k-1] < 8001)   dy[k][l+gy[k-1]] = true;
                if(l-gy[k-1] > -1)     dy[k][l-gy[k-1]] = true;
            }
        }
    }

    if( dx[iy][x] && dy[iy][y] ) printf ("Yes\n");
    else    printf ("No\n");


    return 0;
}

