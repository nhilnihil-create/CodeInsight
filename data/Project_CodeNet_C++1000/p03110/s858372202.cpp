#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define INF 1000000000

int main() {
    int n;
    double x,ans=0;
    string u;
    cin >> n;
    rep(i,n){
        cin >> x >> u;
        if (u=="JPY") ans += x;
        else ans += x*380000;
    }
    cout << ans << endl;
}