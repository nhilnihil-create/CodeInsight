#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    if(n == 1e5 || n == 1e4 || n == 1e3 || n == 10) cout << 10 << endl;
    else {
        int a = n / 10000;
        int b = (n - 10000 * a) / 1000;
        int c = (n - 10000 * a - 1000 * b) / 100;
        int d = (n - 10000 * a - 1000 * b - 100 * c) / 10;
        int e = n % 10;
        cout << a + b + c + d + e << endl;
    } 
    return 0;
}