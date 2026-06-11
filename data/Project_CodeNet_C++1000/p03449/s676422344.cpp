#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N;
    cin >> N;

    vector<int> upper(N);
    vector<int> lower(N);
    for (int i = 0; i < N; i++)
    {
        cin >> upper[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> lower[i];
    }

    int sum;
    int mx = -1;
    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int k = 0; k <= i; k++)
        {
            sum += upper[k];
        }
        for (int j = i; j < N; j++)
        {
            sum += lower[j];
        }
        mx = max(mx, sum);
    }
    int ans = mx;
    cout << ans << endl;
}