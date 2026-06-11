#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    int a = x2-x1;
    int b = y2-y1;
    x3 = x2-b;;
    y3 = y2+a;
    x4 = x1-b;
    y4 = y1+a;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}