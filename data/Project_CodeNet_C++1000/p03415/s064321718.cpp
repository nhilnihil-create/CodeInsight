#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,j;
    char a[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    cout << a[0][0] << a[1][1] << a[2][2] << endl;

    return 0;
}