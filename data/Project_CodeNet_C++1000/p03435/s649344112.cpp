#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'

int main(){
    int c[3][3];
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            cin >> c[i][j];
        
    
    int a[3], b[3];
    a[0] = 0;
    for(int i=0; i<3; ++i)
        b[i] = c[0][i]-a[0];

    a[1] = c[1][0]-b[0];
    a[2] = c[2][0]-b[0];

    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            if(c[i][j] != a[i]+b[j]){
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
}
