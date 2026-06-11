#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> t(n), x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
    }
    
    int ntime = 0, nx = 0, ny = 0;
    string ans = "Yes";
    for (int i = 0; i < n; i++)
    {
        int time = t[i] - ntime;
        int distance = abs(x[i] - nx) + abs(y[i] - ny);
        if(time < distance)
        {
            ans = "No";
        }
        else
        {
            if((time - distance) % 2 != 0)ans = "No";
        }
        ntime = t[i];
        nx = x[i];
        ny = y[i];
    }
    cout << ans << endl;
}
