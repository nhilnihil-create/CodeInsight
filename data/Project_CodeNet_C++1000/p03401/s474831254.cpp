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

    vector<int> A;
    A.push_back(0);

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        A.push_back(num);
    }
    A.push_back(0);

    N += 2;

    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += abs(A[i + 1] - A[i]);
    }
    // printf("sum = %lld\n", sum);

    //観光スポットiを消して出力
    ll ans;
    for (int i = 1; i <= N - 2; i++)
    {
        // ans = sum - abs(A[i + 1] - A[i]) - abs(A[i] - A[i - 1]) + abs(A[i + 1] - A[i - 1]);
        ans = sum - (abs(A[i] - A[i - 1]) + abs(A[i + 1] - A[i])) + abs(A[i + 1] - A[i - 1]);
        cout << ans << endl;
    }
    return (0);
}