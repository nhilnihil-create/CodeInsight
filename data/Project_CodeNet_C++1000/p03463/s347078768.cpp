#include <bits/stdc++.h>
using namespace std;
#define alphanso                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if ((abs(a - b) + 1) % 2 == 0)
        cout << "Borys";
    else
        cout << "Alice";
    return 0;
}