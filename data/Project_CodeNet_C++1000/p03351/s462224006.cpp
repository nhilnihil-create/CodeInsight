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
    int n, m, a, b, c, d;
    string s, t;
    cin >> a >> b >> c >> d;
    bool ok = false;
    if(abs(a-c)<=d ||(abs(a-b)<=d&&abs(b-c)<=d)) ok = true;
    if (ok) Yes();
    else No();
}
