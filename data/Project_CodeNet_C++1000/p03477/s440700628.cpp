#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
void Yes() {
    cout << "Yes" << endl;
}
void No() {
    cout << "No" << endl;
}
int main(void) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e = a + b;
    int f = c + d;
    if(e > f) cout << "Left";
    else if(e == f) cout << "Balanced";
    else cout << "Right";
}
