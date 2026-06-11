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
    vector<int> x(3);
    rep(i, 3) cin >> x[i];
    sort(x.begin(), x.end());
    if(x[0]==x[1]) cout << x[2];
    else cout << x[0];
}
