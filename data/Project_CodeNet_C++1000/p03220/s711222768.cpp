#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, T, A;
    cin >> N >> T >> A;
    double ans = 1000;
    int ans_n = 0;
    for (int i = 1; i <= N; i++)
    {
        double H;
        cin >> H;
        double tmp = T - H * 0.006;
        double sa = abs(A - tmp);
        if (sa < ans)
        {
            ans = sa;
            ans_n = i;
        }
    }
    cout << ans_n << endl;
}