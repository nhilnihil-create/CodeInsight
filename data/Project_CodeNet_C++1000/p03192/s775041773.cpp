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
    int num = 0;
    int a = n / 1000;
    int b = (n - 1000 * a) / 100;
    int c = (n - 1000 * a - 100 * b) / 10;
    int d = n % 10;
    if(a == 2) num++;
    if(b == 2) num++;
    if(c == 2) num++;
    if(d == 2) num++;
    cout << num << endl;
    return 0;
}