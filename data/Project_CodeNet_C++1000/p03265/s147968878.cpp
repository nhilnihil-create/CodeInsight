#include<bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a,b;
    a = x2-x1;
    b = y2-y1;
    cout << x2-b << " " << y2+a << " " << x2-b-a << " " << y2+a-b;
}