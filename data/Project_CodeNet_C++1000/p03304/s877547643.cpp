#include <bits/stdc++.h>
using namespace std;
int main(){
    long n,m,d;
    cin >> n >> m >> d;
    long k;
    if(d==0) k = n;
    else k = 2*(n-d);
    cout << fixed << setprecision(10) << double(k*(m-1))/double(n*n) << endl;
}