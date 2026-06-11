#include <bits/stdc++.h>
using namespace std;

int main(){
    double n,m,d;
    cin >> n >> m >> d;
    double ans = 2*(n-d)*(m-1)/(n*n);
    double zero = 0.0;
    if(d == zero) ans /= 2;
    cout << fixed << setprecision(8) << ans << endl; 
    cin >> n;   
}