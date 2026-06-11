#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

pair<int, int> join(pair<int, int> a, const pair<int, int> &b)
{
    for (int x : {b.first, b.second})
    {
        if (a.first < x) swap(a.first, x);
        if (a.second < x) swap(a.second, x);
    }
    return a;
}

void rec(pair<int, int> a[], int N)
{
    if (N == 1) return;
    N /= 2;
    rec(a, N);
    rec(a + N, N);
    for (int i = 0; i < N; ++i)
        a[i + N] = join(a[i + N], a[i]);
}

int main()
{
#ifdef jcg
    assert(freopen("input.in", "r", stdin));
//    assert(freopen("output.out", "w", stdout));
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    N = 1 << N;

    vector<pair<int, int>> a(N);
    for (auto &p : a)
        cin >> p.first;

    rec(&a[0], N);

    int best = 0;
    for (int i = 1; i < N; ++i)
        cout << (best = max(best, a[i].first + a[i].second)) << endl;

    return 0;
}
