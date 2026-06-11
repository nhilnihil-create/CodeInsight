#include <bits/stdc++.h>
using namespace std;

int x,a[1100],c[1100],d[1100],b[1100],maks=0,numb=0,H;
int main(){
    cin>>x;
    for(int i=1;i<=x;i++){
        cin>>a[i];
    }
    for(int m=1;m<=1000;m++){
        d[m]=m;
    }
    for(int k=1;k<=x;k++){
        c[k]=0;
    }
    for(int l=1;l<=x;l++){
        for(int z=1;z<=1000;z++){
        if(a[l]==d[z]){
            c[z]++;
        }
        }
    }
    for(int p=1;p<=1000;p++){
        if(c[p]>=1){
            b[p]=c[p]-1;
        }
        else if (c[p]==0){
            b[p]=0;
        }
    }
    for(int n=1;n<=1000;n++){
        numb+=b[n];
    }
   cout<<x-numb;
    }