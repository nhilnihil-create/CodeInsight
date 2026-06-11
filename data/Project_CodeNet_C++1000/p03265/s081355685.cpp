#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 100000

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a = x2 - x1;
    int b = y2 - y1;
    int x3 = x2 - b;
    int y3 = y2 + a; 
    int x4 = x3 - a; 
    int y4 = y3 - b;
    //cout << a << " " << b << endl;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}
