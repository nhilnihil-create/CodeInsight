#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    long long asum = 0;
    long long bsum = 0;
    vector<pair<long long, pair<long long, long long>>> v;

    for (int i = 0; i < N; i++)
    {
        long long a, b;
        cin >> a >> b;
        bsum += b;
        v.push_back(make_pair(a + b, make_pair(a, b)));
    }

    sort(v.rbegin(), v.rend());

    for (int i = 0; i < N; i += 2)
    {
        asum += v[i].second.first;
        bsum -= v[i].second.second;
    }

    cout << asum - bsum << endl;
}