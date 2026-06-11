#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int mx = -1e9, sum = 0;
    for(int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        mx = max(mx, l);
        sum += l;
    }

    if(mx < sum - mx)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
