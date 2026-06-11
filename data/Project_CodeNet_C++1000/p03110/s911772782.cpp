#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N;
    double x, ans = 0;
    string v;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> v;
        if (v == "JPY")
            ans += x;
        else
            ans += x * 380000;
    }
    cout << fixed << setprecision(6) << ans;
}