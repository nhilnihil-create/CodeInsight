#include<bits/stdc++.h>
using namespace std;
int a[4][4];
int main(){
    for(int i = 1; i<= 3;i++) 
        for(int j = 1;j <= 3;j ++) 
            cin>>a[i][j];
    for(int k = -1000;k <= 1000;k++) {
        int a2,a3,b1,b2,b3;
        int a1 = k;
        b1 = a[1][1] - k;
        b2 = a[1][2] - k;
        b3 = a[1][3] - k;
        a2 = a[2][1] - b1;
        a3 = a[3][1] - b1;
        bool flg = false;
        if(a[2][2] != a2 + b2) flg = true;
        if(a[2][3] != a2 + b3) flg = true;
        if(a[3][2] != a3 + b2) flg = true;
        if(a[3][3] != a3 + b3) flg = true;
        if(!flg) {
            cout<<"Yes"<<endl;return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
