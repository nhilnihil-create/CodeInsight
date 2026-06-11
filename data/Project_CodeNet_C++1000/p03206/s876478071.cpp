#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<x;i++)

int getmd(int a,int b,int c,int d){
    return abs(a-c)+abs(b-d);
}

int main(){
    int d;
    cin >> d;

    if(d==25)   puts("Christmas");
    if(d==24)   puts("Christmas Eve");
    if(d==23)   puts("Christmas Eve Eve");
    if(d==22)   puts("Christmas Eve Eve Eve");
    return 0;
}