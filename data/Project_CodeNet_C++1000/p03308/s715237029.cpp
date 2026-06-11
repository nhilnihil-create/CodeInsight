#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll max = *max_element(a.begin(), a.end());
    ll min = *min_element(a.begin(), a.end());

    cout << abs(max - min) << endl;

    return 0;
}
