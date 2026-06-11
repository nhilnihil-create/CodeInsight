#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
int main()
{
    int n,k;
    cin >> n >> k;
    ll cnt = 0;
    for (int i = k+1; i <= n;i++){
        int tmp = n % i;
        int num = n / i;
        cnt += num * (i - k);
        cnt += max(0, tmp - max(0,(k-1)));
    }
    cout << cnt << endl;
}
