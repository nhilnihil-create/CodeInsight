#include <bits/stdc++.h>
using namespace std;

int main(){
    int vec[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> vec[i][j];
        }
        }

int a[3];
int b[3];

a[0]=0;
b[0]=vec[0][0];
b[1]=vec[0][1];
b[2]=vec[0][2];
a[1]=vec[1][0]-vec[0][0];
a[2]=vec[2][0]-vec[0][0];

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(vec[i][j]!=a[i]+b[j]){
            cout << "No" << endl;
            return 0;
        }
    }
}

cout << "Yes" << endl;
    }