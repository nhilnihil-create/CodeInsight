#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int c[3][3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> c[i][j];
        }
    }

    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            for(int k=0; k<=100; k++){
                int b1 = c[0][0] -i;
                int b2 = c[0][1] -i;
                int b3 = c[0][2] -i;

                if(j+b1 == c[1][0] && k+b1 == c[2][0] &&
                   j+b2 == c[1][1] && k+b2 == c[2][1] &&
                   j+b3 == c[1][2] && k+b3 == c[2][2]){
                       
                       cout << "Yes" << endl;
                       return 0;
                   }
            }
        }
    }
    cout << "No" << endl;
}