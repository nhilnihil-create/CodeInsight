#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

// ans = ceil((double)(N - 1) / (K - 1))

int main(void)
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int ans = 0;
    int right = 0;
    while (true)
    {
        if (ans == 0)
        {
            right += K;
        }
        else
        {
            right += K - 1;
        }
        ans++;

        if (right >= N)
        {
            break;
        }
    }
    cout << ans << endl;
}