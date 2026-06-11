
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll sum = 0, mi_n = - 1;
    while(n >= 10){
        sum += n % 10;
        mi_n += 9;
        n /= 10;
    }
    sum += n;
    mi_n += n;
    cout << max(sum, mi_n) << endl;
    return 0;
}
