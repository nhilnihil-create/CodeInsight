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
int main() {
    int a, b, x; cin >> a >> b >> x;
    bool ok = true;
    if(a>x || (a+b)<x) ok = false;
    cout << ((ok)?"YES":"NO");
}

