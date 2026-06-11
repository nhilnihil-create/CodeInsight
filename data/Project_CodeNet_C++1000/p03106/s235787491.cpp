#include <bits/stdc++.h>

using namespace std;

int a, b, k;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> k;

    for(int i = 1; i <= min(a, b); i++)
    {
        if(a % i == 0 && b % i == 0)
            v.push_back(i);
    }

    cout << v[v.size() - k];

    return 0;
}
