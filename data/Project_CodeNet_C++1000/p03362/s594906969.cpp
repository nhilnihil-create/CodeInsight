#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
#define ll long long
const int INF = 0x7fffffff;
const int N = 5e3 + 5;
bool prime(ll n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    ll i, j, k;
    ll n, m, t;
    ll count = 0;
    cin >> n;
    for (i = 11; i <= 55555; i += 10)
    {
        if (prime(i))
        {
            cout << i << " ";
            count++;
        }
        if (count == n)
            break;
    }
}