#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, Expensive, Sum = 0;
    long p;
    cin >> N;
    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        cin >> p;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), greater<>());

    Expensive = v[0] / 2;

    for (int i = 1; i < v.size(); i++)
    {
        Sum += v[i];
    }

    Sum += Expensive;

    cout << Sum;
}