#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)

using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    multiset<int, greater<int>> ms;
    for (int a : A)
        ms.insert(a);

    // make pair
    int npair = 0;
    while (!ms.empty())
    {
        auto it_a = ms.begin();
        int a = *it_a;
        ms.erase(it_a);

        int power_of_two = pow(2, (int)floor(log2(a)) + 1);
        int b = power_of_two - a;
        auto it_b = ms.find(b);
        if (it_b == ms.end())
            continue;
        ms.erase(it_b);
        npair++;
    }

    cout << npair << endl;
}