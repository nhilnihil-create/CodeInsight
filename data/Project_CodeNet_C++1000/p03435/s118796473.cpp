#include<bits/stdc++.h>
using namespace std;
int main(){
    int C[10][10],x[10],y[10];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> C[i][j];
        }
    }
    x[0]=0;
    for(int i=0;i<3;i++)y[i]=C[0][i]-x[0];
    for(int i=0;i<3;i++)x[i]=C[i][0]-y[0];

    bool a=true;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(C[i][j]!=x[i]+y[j])a=false;
        }
    }
    cout << (a ? "Yes" : "No") << endl;
    return 0;
}