#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a(10);

    for (int i = 0; i < 4; i++)
    {
        cin >> n;
        a[n]++;
    }
    
    if (a[1] && a[4] && a[7] && a[9])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    
}