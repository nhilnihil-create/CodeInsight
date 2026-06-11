#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int main()
{

    int n;
    cin >> n;

    vector<ll> x;
    vector<ll> s;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        x.push_back(a);
        s.push_back(a);
    }
    sort(x.begin(), x.end());

    for (int i = 0; i < n; i++)
    {
        if (s[i] < x[n / 2])
        {
            cout << x[n / 2] << endl;
        }
        else
        {
            cout << x[(n / 2) - 1] << endl;
        }
    }

    return 0;
}
