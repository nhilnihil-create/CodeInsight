#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string b;
    char base[2][2] = {{'A','T'},{'C','G'}};
    cin >> b;

    for(int i=0;i<2;i++) {
        for (int j=0;j<2;j++) {
            if(b[0] == base[i][j]) {
                cout << base[i][(j+1)%2]  << endl;
                break;
            }
        }
    }
    return 0;
}
