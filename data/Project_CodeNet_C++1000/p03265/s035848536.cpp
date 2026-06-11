#include <bits/stdc++.h>
using namespace std;

int main(void){
    int x[4], y[4], tmp1, tmp2;
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    tmp1 = x[1] - x[0];
    tmp2 = y[1] - y[0];
    x[2] = x[1] - tmp2;
    y[2] = y[1] + tmp1;
    x[3] = x[2] - tmp1;
    y[3] = y[2] - tmp2;
    cout << x[2] << ' ' << y[2] << ' ' << x[3] << ' ' << y[3] << endl;
    return 0;
}