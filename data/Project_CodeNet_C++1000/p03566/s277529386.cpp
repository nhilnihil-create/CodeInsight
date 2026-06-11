#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> t(n), v(n); 
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t.at(i);
        sum += t.at(i);
    }
    for (int i = 0; i < n; i++) cin >> v.at(i); 
    
    vector<double> maxv(sum * 2 + 1);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= t.at(i) * 2; j++)
        {
            if (maxv.at(s + j) > 0) maxv.at(s + j) = min(maxv.at(s + j), v.at(i));
            else maxv.at(s + j) = v.at(i);
        }
        s += t.at(i) * 2;
    }
    
    maxv.at(0) = 0;
    maxv.at(sum * 2) = 0;
    
    for (int i = 1; i <= sum * 2; i++)
    {
        maxv.at(i) = min(maxv.at(i), maxv.at(i - 1) + 0.5);
    }
    for (int i = sum * 2 - 1; i >= 0; i--)
    {
        maxv.at(i) = min(maxv.at(i), maxv.at(i + 1) + 0.5);
    }
    
    double ans = 0; 
    for (int i = 0; i < sum * 2; i++)
    {
        ans += (maxv.at(i) + maxv.at(i + 1)) * 0.5 / 2;
    }
    
    printf("%.10f\n", ans);
}