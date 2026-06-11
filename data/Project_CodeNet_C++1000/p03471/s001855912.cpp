#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
int main(){
    int n, m;
    cin >> n >> m;
    m/=1000;
    int x, y, g;
    if(!find_any_solution(9,4,m-n,x,y,g)) {cout << "-1 -1 -1"; return 0;}
    //cout << x << " " << y <<endl;
    while(x<0){
        x += 4/g;
        y -= 9/g;
    }
    //cout << x << " " << y <<endl;
    while(y<0){
        x -= 4/g;
        y += 9/g;
    }
    //cout << x << " " << y <<endl;
    if(x<0 || y<0 || n-x-y<0) {cout <<  "-1 -1 -1"; return 0;}
    cout << x << " " << y << " " << n-x-y;

}
