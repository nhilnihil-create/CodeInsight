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
    int a, b, c; cin >> a >> b >> c;
    bool ok = false;
    if(a+b >= c) ok = true;
    if(ok) Yes();
    else No();
}
