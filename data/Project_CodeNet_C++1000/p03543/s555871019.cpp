#include <bits/stdc++.h>
using namespace std;

int main() {
    char c[4];
    int flg = 0;
    cin >> c;

    if(c[0]==c[1] && c[0]== c[2])
        flg = 1;
    if(c[3]==c[1] && c[3]== c[2])
        flg = 1;

    if(flg)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}