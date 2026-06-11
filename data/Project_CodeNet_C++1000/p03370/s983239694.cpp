#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, X, m, Sum = 0, Ingredient, Max;
    cin >> N >> X;
    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        cin >> m;
        v.push_back(m);
        Sum += m;
    }

    if (Sum - X != 0)
    {

        sort(v.begin(), v.end());
        Ingredient = v[0];

        Max = ((X - Sum) / Ingredient) + N;
        cout << Max;
    }

    if (Sum - X == 0)
    {
        cout << N;
    }
}