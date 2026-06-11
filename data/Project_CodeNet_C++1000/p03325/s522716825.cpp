#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

// 、「3 倍する」 操作を何回かやっておくことで、「2 で割る」 操作の回数が増えたり減ったりするで
// しょうか？答えは No です。なぜなら、奇数を掛けて 2 で割れる回数が増えることはなく、整数を掛けて
// 2 で割れる回数が減ることがないからです。

int main(void)
{
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        while (a[i] % 2 == 0)
        {
            cnt++;
            a[i] /= 2;
        }
    }
    cout << cnt << endl;
}