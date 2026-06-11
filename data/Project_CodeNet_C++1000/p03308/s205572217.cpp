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
    
    int max_diff = 0;
    
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            max_diff = max(max_diff, abs(a[i] - a[j]));
        }
            
    }
            
    cout << max_diff << endl;
    return 0;
}
