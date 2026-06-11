#include <bits/stdc++.h>

using namespace std;

#define INF 1000007
#define MOD 1000000007
#define maxn 100
#define int long long int
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int mpow(int N, int P, int M) //繰り返し自乗法
{
    if (P == 0)
        return 1;
    if (P % 2 == 0)
    {
        int t = mpow(N, P / 2, M);
        return t * t % M;
    }
    return N * mpow(N, P - 1, M) % M;
}

int counter(int x)
{ //bit計算
    if (x == 0)
        return 0;
    return counter(x >> 1) + (x & 1);
}

vector<bool> prime(maxn + 1, true); //素数テーブル
void prime_table(void)
{
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= maxn; i++)
    {
        if (!prime[i])
        {
            continue;
        }
        for (int j = i + i; j <= maxn; j += j + i)
        {
            prime[j] = false;
        }
    }
}

bool IsPrime(int num)
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}
signed main()
{
    int N;
    cin >> N;
    vector<int> AB;
    int B = 0;
    int ans = 0;
    rep(i, N)
    {
        int a, b;
        cin >> a >> b;
        B += b;
        AB.push_back(a + b);
    }
    ans -= B;
    sort(AB.begin(), AB.end(), greater<int>());
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
            ans += AB[i];
    }
    cout << ans << endl;
}
