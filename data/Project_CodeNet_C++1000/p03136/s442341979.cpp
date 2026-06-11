#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int N, i, t, s = 0;
    vector<int> l;

    cin >> N;

    for (i = 0; i < N; i++)
    {
        cin >> t;
        l.push_back(t);
    }

    sort(l.begin(), l.end(), cmp);

    for (t = 0; t < i - 1; t++)
        s += l[t];

    if (s > l[t])
        cout << "Yes";
    else
        cout << "No";

    return 0;
}