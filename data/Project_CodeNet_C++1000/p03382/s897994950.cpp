#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a;

int main()
{
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ansb = a.back();

    vector<double> diff(N);
    for (int i = 0; i < N; i++)
    {
        diff[i] = abs((double)a[i] - (double)ansb / 2.0);
    }

    int ansa = a[distance(diff.begin(), min_element(diff.begin(), diff.end()))];

    cout << ansb << " " << ansa << endl;
    return 0;
}
