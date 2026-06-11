#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    int Q;
    cin >> Q;

    int MAX = 10e5+1;

    vector<int> prime(MAX, 1);
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i * i < MAX; i++)
    {
        if (prime[i])
        {
            for (int j = 2; j * i < MAX; j++)
            {
                prime[i * j] = 0;
            }
        }
    }

    vector<int> N(MAX, 0);
    for (int i = 0; i < MAX; i++)
    {
        if (prime[i] && prime[(i + 1) / 2])
        {
            N[i] = 1;
        }
    }

    vector<int> a(MAX + 1, 0);
    for (int i = 0; i < MAX; i++)
    {
        a[i + 1] = a[i] + N[i];
    }

    for (int i = 0; i < Q; i++)
    {
        int r, l;
        cin >> l >> r;
        cout << a[++r] - a[l] << endl;
    }

    return 0;
}
