#include<bits/stdc++.h>
using namespace std;
#define db double
db n, m, d;

int main(){
    cin >> n >> m >> d;
    db ans = ((db)1 - d/n) * ((m - (db)1)/n);
    cout << fixed << setprecision(10) << (d != 0 ? (db)2 : (db)1) * ans << endl;
    return 0;
}