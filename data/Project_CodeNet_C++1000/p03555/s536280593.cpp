#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
void Yes() {
    cout << "YES" << endl;
}
void No() {
    cout << "NO" << endl;
}
int main(void) {
    string s, t; cin >> s >> t;
    reverse(s.begin(), s.end());
    if(s == t) Yes();
    else No();
}
