#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,x,y;
    int hantei = 0;
    cin >> n >> m >> x >> y;
    int X[n],Y[m];
    for(int i=0;i<n;i++){
        cin >> X[i];
        if(X[i] == y || X[i]>y){
            hantei = 1;
            break;
        }
    }
    for(int i=0;i<m;i++){
        cin >> Y[i];
        if(Y[i] == x || Y[i]<x){
            hantei = 1;
            break;
        }
    }
    if(hantei == 1) cout << "War" << endl;
    else{
        sort(X,X+n);
        sort(Y,Y+m);
        if(Y[0]-X[n-1] > 0) cout << "No War" << endl;
        else cout << "War" << endl;
    }
}