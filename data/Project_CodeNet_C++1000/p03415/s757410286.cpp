#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    char C[3][3];
    string ans;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> C[i][j];
            if (i == j) {
                ans += C[i][j];
            }
        }
    }
    cout << ans << endl;
}