#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;

int main(void)
{
    int N, K;
    cin >> N >> K;

    int ans;
    if (N % K == 0)
    {
        ans = 0;
    }
    else
    {
        ans = 1;
    }
    cout << ans << endl;
    return (0);
}