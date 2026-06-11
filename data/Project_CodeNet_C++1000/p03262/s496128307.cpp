#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
}

int main(void)
{
    int N, X;
    cin >> N >> X;

    vector<int> x(N);
    int mx = -1;
    deque<int> diff;
    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
        temp = abs(X - x[i]);
        mx = max(mx, temp);
        diff.push_back(temp);
    }

    //debug
    // for (int i = 0; i < N; i++)
    // {
    //     cout << diff[i] << " ";
    // }
    // printf("\n");

    // 一番最大の公約数を見つける。
    int ans = diff[0];
    for (int i = 0; i < N; i++)
    {
        ans = gcd(ans, diff[i]);
    }

    printf("%d\n", ans);
    return (0);
}