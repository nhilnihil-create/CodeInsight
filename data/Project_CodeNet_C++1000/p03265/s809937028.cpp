#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int xi = x2;
    int yi = y2;
    rep(i, 2){
        int _dx = -dy;
        int _dy = dx;
        dx = _dx;
        dy = _dy;
        xi = xi + dx;
        yi = yi + dy;
        cout << xi << " " << yi;
        if (i == 0) cout << " ";
    }
    cout << endl;
}