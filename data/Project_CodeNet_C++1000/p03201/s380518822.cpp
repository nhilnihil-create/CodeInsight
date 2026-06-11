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

    sort(A.rbegin(), A.rend());
    unordered_map<int, set<int>> a_to_indice;
    rep(i, N) a_to_indice[A[i]].insert(i);

    // make pair
    int npair = 0;
    rep(i, N)
    {
        int a = A[i];
        // cout << "--------" << endl;
        // cout << a << endl;
        if (a == 0) // already paired
            continue;
        a_to_indice[a].erase(i);
        A[i] = 0;

        int power_of_two = pow(2, (int)floor(log2(a)) + 1);
        int b = power_of_two - a;
        if (!a_to_indice[b].empty())
        {
            // cout << a << endl;
            int index_b = *a_to_indice[b].begin();
            // cout << index_b << endl;
            a_to_indice[b].erase(index_b);
            A[index_b] = 0;
            npair++;
        }
    }

    cout << npair << endl;
}