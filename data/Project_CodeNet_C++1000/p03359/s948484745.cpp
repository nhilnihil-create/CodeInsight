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
    int n, m, a, b, c;
    string s, t;
    cin >> a >> b;
    int ans = a-1;
    if(a <= b) ans++;
    cout << ans;
    
}
