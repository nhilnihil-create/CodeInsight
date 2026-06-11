#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    int max_p = 0;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        ans += p;
        max_p = max(max_p, p);
    }
    ans -= max_p / 2;
    cout << ans << endl;
}