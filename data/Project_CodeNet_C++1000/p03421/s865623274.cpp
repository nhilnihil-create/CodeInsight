#include<bits/stdc++.h>

using namespace std;

const int MaxN = 2e5 + 25;
const int MOD = 1e9 + 7;

void make(vector <long long> & v)
{
    map<long long, int> mp;
    for(long long x : v)
        mp[x];

    int cur = 0;

    for(map<long long, int>:: iterator it = mp.begin(); it != mp.end(); ++it)
        it -> second = ++cur;

    for(long long & x : v)
        x = mp[x];
}

int main()
{
//    freopen("input.txt", "r", stdin);

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    vector <long long> v;

    long long n, a, b;
    cin >> n >> a >> b;

    if(a + b - 1 > n || a * b < n)
    {
       cout << -1 << '\n';
       return 0;
    }

    long long k = n - (a + b - 1);

    for(long long i = a * b - a + 1; i <= a * b; ++i)
        v.push_back(i);

    long long B = b - 1;

    while(k)
    {
        v.push_back((B - 1) * a + 1);

        long long p = min(k, a - 1);

        k -= p;

        for(int i = 2; i <= a && p; ++i, --p)
            v.push_back((B - 1) * a + i);

        --B;
    }

    while(B)
    {
        v.push_back((B - 1) * a + 1);
        --B;
    }

    make(v);

    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << '\n';

    return 0;
}
