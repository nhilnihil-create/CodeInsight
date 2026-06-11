#include <bits/stdc++.h>
using namespace std;

void divisor(vector<int> &d, int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            d.push_back(i);
            if(i * i != n)d.push_back(n / i);
        }
    }
    
}

int main()
{
    long long n,m;
    cin >> n >> m;

    vector<int> mm;
    divisor(mm, m);
    sort(mm.begin(), mm.end());
    //for (int i = 0; i < mm.size(); i++)cout << mm[i] << " ";cout << endl;

    int ans = mm[mm.size() - 1];
    for (int i = 0; i < mm.size(); i++)
    {
        if(mm[i] * n > m)
        {
            ans = mm[i - 1];
            break;
        }
    }

    
    cout << ans << endl;
}