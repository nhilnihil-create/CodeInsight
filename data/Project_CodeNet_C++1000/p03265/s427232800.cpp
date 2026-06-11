#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x1, y1, x2, y2, x3, y3, x4, y4; cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2-x1, dy = y2-y1;
    x3 = x2 - dy; y3 = y2 + dx;
    x4 = x3 - dx; y4 = y3 - dy;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}
