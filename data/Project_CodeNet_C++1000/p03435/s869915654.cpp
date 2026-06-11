#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
int c[3][3];
int t = 0;
int main() {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> c[i][j];
        }
    }
    vector<int>a(3);
    vector<int>b(3);
    for(int i = 0; i <= 100; i++){
        a[0] = i;
        b[0] = c[0][0] - a[0];
        b[1] = c[0][1] - a[0];
        b[2] = c[0][2] - a[0];
        a[1] = c[1][0] - b[0];
        a[2] = c[2][0] - b[0];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(c[i][j] == a[i] + b[j]){
                    t++;
                }
            }
        }
        if(t == 9) {
            cout << "Yes" << endl;
            return 0; 
        }
    }   
    cout << "No" << endl;
    
    return 0;
}