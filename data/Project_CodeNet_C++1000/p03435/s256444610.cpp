#include<bits/stdc++.h>
using namespace std;

int main(){
    int c[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            cin >> c[i][j];
    }
    bool flg = false;
    for(int i=0; i<=c[0][0]; i++){
        int a_1 = i;
        int b_1 = c[0][0] - i;
        int a_2 = c[1][0] - b_1;
        int a_3 = c[2][0] - b_1;
        int b_2 = c[0][1] - a_1;
        int b_3 = c[0][2] - a_1;
        if(a_2<0 || a_3<0 || b_2<0 || b_3<0){
            flg = false; continue;
        }
        if((a_2+b_2==c[1][1] && a_2+b_3==c[1][2]) && (a_3+b_2==c[2][1] && a_3+b_3==c[2][2])){
            flg = true; break;
        }
    }
    if(flg) cout << "Yes" << endl;
    else    cout << "No"  << endl;
    return 0;
}