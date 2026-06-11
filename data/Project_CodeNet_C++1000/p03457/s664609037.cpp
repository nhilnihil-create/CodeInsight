#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

int max(int a, int b){
        if(a>b) return a;
        else return b;
}

int min(int a, int b){
        if(a>b) return b;
        else return a;
}

int main(int argc, char* argv[]){
        char* ptr=NULL;
        int N = 0;
        int t1=0, t2=0, x1=0, x2=0, y1=0, y2=0;
        int dt=0, dx=0, dy=0;
        int possible = 1;

        cin >> N;

        for(int i=1; i<=N && possible==1; i++){
                cin >> t2 >> x2 >> y2 ;
                dt = t2 - t1;
                dx = x2 - x1;
                dy = y2 - y1;

                if((dt+dx+dy)%2!=0){ possible=0; break; }
                if((dt+dx-dy)%2!=0){ possible=0; break; }

                int u = (dt+dx+dy)/2;
                int v = (dt+dx-dy)/2;

                if( max(0,dx)>min(u,v) ){ possible=0; break; }

                t1 = t2;
                x1 = x2;
                y1 = y2;

        }

        if(possible==1){printf("Yes\n");}
        else{printf("No\n");}

        return 0;
}