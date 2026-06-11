#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define PI acos(-1)

int main(){
    int x,y,x2,y2;
    int x_d,y_d;
    cin >> x >> y >> x2 >> y2;
    x_d = x - x2;
    y_d = y - y2;
    cout << x2 + y_d << " " << y2 - x_d << " " << x + y_d << " " << y - x_d <<  endl;
}
