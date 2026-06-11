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

    vector<int> rui_upper(N + 1, 0);
    vector<int> rui_lower(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        rui_upper[i + 1] = rui_upper[i] + upper[i];
        rui_lower[i + 1] = rui_lower[i] + lower[i];
    }

    // debug
    // for (int i = 1; i < N + 1; i++)
    // {
    //     cout << rui_lower[i] << " ";
    // }

    int sum = 0;
    int mx = -1;
    for (int i = 1; i < N + 1; i++)
    {
        sum = rui_upper[i] + rui_lower[N] - rui_lower[i - 1];
        // printf("%d %d\n", rui_upper[i], rui_lower[N] - rui_lower[i - 1]);
        mx = max(sum, mx);
    }
    cout << mx << endl;
}