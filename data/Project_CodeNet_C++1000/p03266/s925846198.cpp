#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n,k;
    cin >> n >> k;
    
    if (k%2==0)
    {
        k = k/2;
        int num;
        num = n/k;
        int gu, ki;
        ki = num/2; gu = num/2;

        if (num%2==1)
        {
            ki++;
        }
        ll ans = 0;
        ll ki_sum = 1;
        ll gu_sum = 1;
        rep(i,3)
        {
            ki_sum *= ki;
            gu_sum *= gu;
        }
        ans = ki_sum+gu_sum;
        cout << ans << endl;
        return 0;
    }

    if (k % 2 == 1)
    {
        int num;
        num = n / k;
        ll ans = 1;
        rep(i, 3)
        {
            ans *= num;
        }
        cout << ans << endl;
        return 0;
    }
}