#include <bits/stdc++.h>

using namespace std;

int main()
{
        ios::sync_with_stdio(false);

        int a, b;

        cin >> a >> b;

        int sum, sub, m;

        sum = a+b;
        sub = a-b;
        m = a*b;

        if(sum >= sub && sum >= m)
                cout << sum << endl;
        else if(sub >= sum && sub >= m)
                cout << sub << endl;
        else
                cout << m << endl;

        return 0;
}