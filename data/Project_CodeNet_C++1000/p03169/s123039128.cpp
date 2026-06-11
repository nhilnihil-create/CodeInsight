//thuanqvbn03
#include <bits/stdc++.h>
using namespace std;

int n;
long double dp[301][301][301];

long double Cal(int N, int ones, int twos, int threes)
{
    if (ones == 0 && twos == 0 && threes == 0)
    {
        return 0.0;
    }
    if (dp[ones][twos][threes] != 0.0)
    {
        return dp[ones][twos][threes];
    }
    int nonEmptyPlates = ones + twos + threes;
    long double p_wasted = 1.0 - (long double)nonEmptyPlates / N;
    long double p1 = 0.0, p2 = 0.0, p3 = 0.0;
    if (ones > 0)
    {
        p1 = (long double)ones / nonEmptyPlates * Cal(N, ones - 1, twos, threes);
    }
    if (twos > 0)
    {
        p2 = (long double)twos / nonEmptyPlates * Cal(N, ones + 1, twos - 1, threes);
    }
    if (threes > 0)
    {
        p3 = (long double)threes / nonEmptyPlates * Cal(N, ones, twos + 1, threes - 1);
    }
    dp[ones][twos][threes] = p1 + p2 + p3 + p_wasted / (1 - p_wasted);
    return dp[ones][twos][threes];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int ones = 0, twos = 0, threes = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ones += (x == 1);
        twos += (x == 2);
        threes += (x == 3);
    }
    cout << fixed << setprecision(9) << ones + twos * 2 + threes * 3 + Cal(n, ones, twos, threes) << '\n';
    return 0;
}
