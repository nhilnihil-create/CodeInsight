#include <bits/stdc++.h>
using namespace std;

int n;
int a[110];

int main()
{
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int ma = a[0];
    int mi = a[0];

    for (int i = 0; i < n; i++)
    {
        ma = max(ma,a[i]);
        mi = min(mi,a[i]);
    }
    
    cout << ma-mi << endl;
    
    return 0;
}
