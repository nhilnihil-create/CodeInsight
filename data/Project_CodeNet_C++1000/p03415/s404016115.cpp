#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9;

int main()
{
    char c[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> c[i][j];
    cout << c[0][0] << c[1][1] << c[2][2] << endl;
    return 0;
}
