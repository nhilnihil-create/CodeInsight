#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, L, Sum = 0;
    cin >> N;
    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        cin >> L;
        v.push_back(L);
    }

    sort(v.begin(), v.end(), greater<>());

    for (int i = 1; i < v.size(); i++)
    {
        Sum += v[i];
    }

    if (v[0] < Sum)
    {
        cout << "Yes";
    }

    if (v[0] >= Sum)
    {
        cout << "No";
    }
}