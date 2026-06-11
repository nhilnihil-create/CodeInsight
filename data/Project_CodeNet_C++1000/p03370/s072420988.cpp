#include <iostream>
#include <climits>
#include <map>

using namespace std;

int main()
{
    int q, mass;
    cin >> q >> mass;

    int ans = 0;
    int sml = INT_MAX;

    while(q--)
    {
        int n;
        cin >> n;

        mass -= n;
        sml = min(sml, n);
        ans++;
    }

    ans += (mass / sml);

    cout << ans << endl;

    return 0;
}
