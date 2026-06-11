#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, cnt = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        string x = to_string(i);
        if (x[0] == x[4] && x[1] == x[3])
            cnt++;
    }
    cout << cnt << endl;
}
