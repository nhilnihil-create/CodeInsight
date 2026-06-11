#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N, K;
    cin >> N >> K;

    vector<int> h(N);
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }
    sort(h.begin(), h.end());

    int ans = INF;
    int temp;
    int hmax;
    int hmin;
    for (int i = 0; i < N - K + 1; i++)
    {
        hmin = h[i];
        hmax = h[i + K - 1];
        // printf("hmin = %d, hmax = %d\n", hmin, hmax);
        temp = hmax - hmin;
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return (0);
}