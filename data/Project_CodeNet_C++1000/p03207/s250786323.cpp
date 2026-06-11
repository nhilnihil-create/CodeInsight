#include <stdio.h>

int main(){

    int N,b;

    scanf("%d",&N);

    int T[N],i=0,a;

    while(N>i){

        scanf("%d",&T[i]);
        i++;


    }
    i=0;
    a=T[i];

    while(N-1>i){

        if(a>T[i+1]){

            a=a;


        }
        else{

            a=T[i+1];

        }

       i++;

    }

    b=a/2;
    i=0;
    int sum=0;

    while(N>i){

        sum=sum+T[i];
        i++;


    }

    int G;
    G=sum-b;

    printf("%d",G);





return 0;

}

