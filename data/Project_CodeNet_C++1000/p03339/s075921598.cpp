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

    string S;
    cin >> S;

    ll totalW = 0;
    ll totalE = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'W')
        {
            totalW++;
        }
        else
        {
            totalE++;
        }
    }

    ll soFarW = 0;
    ll soFarE = 0;
    ll sum;
    ll ans = INF;
    for (int i = 0; i < N; i++)
    {
        char current = S[i];
        if (current == 'E')
        {
            soFarE++;
            sum = soFarW + (totalE - soFarE);
            // printf("%d: leftW = %d, rightE = %d\n", i + 1, soFarW, totalE - soFarE);
        }
        else
        {
            sum = soFarW + (totalE - soFarE);
            // printf("%d: leftW = %d, rightE = %d\n", i + 1, soFarW, totalE - soFarE);
        }
        ans = min(ans, sum);

        if (current == 'W')
        {
            soFarW++;
        }
    }
    cout << ans << endl;
}