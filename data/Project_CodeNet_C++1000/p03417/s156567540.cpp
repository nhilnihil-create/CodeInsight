#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
int main()
{
    ll n,m;
    cin >> n >> m;
    if(n == 1 && m == 1){
        cout << 1 << endl;
    }else if (n >=2  && m >= 2){
        cout << (n - 2) * (m - 2) << endl;
    }else{
        cout << max(n, m) - 2 << endl;
     }
}
