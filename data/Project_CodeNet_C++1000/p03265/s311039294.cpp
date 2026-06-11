#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a = x2 - x1;
    int b = y2 - y1;
    cout << x2 - b << endl;
    cout << y2 + a << endl;
    cout << x1 - b << endl;
    cout << y1 + a << endl;
}

