#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int X[n];
    for (int i = 0;i<n;i++){
        cin>>X[i];
    }
    int Y[m];
    for (int i = 0;i<m;i++){
        cin>>Y[i];
    }
    sort(X,X+n);
    sort(Y,Y+m);
    int z = min(Y[0],y);
    if (X[n-1]<z && x<z){
        cout<<"No War";
    }
    else{
        cout<<"War";
    }

    
}
