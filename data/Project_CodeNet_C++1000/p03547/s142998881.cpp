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
    char x, y; cin >> x >> y;
    char ans;
    if(x > y) ans = '>';
    else if(x < y) ans = '<';
    else ans = '=';
    cout << ans;
}
