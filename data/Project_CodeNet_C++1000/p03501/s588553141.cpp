
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int ans = min(a*n,b);
    cout << ans << endl;
}