#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a,b;
    cin >> a >> b;
    int ans = -a;
    rep2(i,1,b-a) ans += i;
    cout << ans << endl;
}