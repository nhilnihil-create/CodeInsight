#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> d(n);
    REP(i, n)
    {
        cin >> d.at(i);
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    cout << d.size() << endl;
}
