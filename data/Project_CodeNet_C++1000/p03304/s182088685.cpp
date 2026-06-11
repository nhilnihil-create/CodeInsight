#include <bits/stdc++.h>
using namespace std;

int main(){
    double n, m, d;
    cin >> n >> m >> d;
    
    double exp = 1;
    if(d != 0 && n > 2 * d) exp = 2 * (n-d) / n;

    exp = exp / n * (m-1);
    cout << fixed << setprecision(10) << exp << endl;
    return 0;
}