#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin>>n;

    int maxa = n/4;
    int maxb = n/7;

    bool exists = false;
    for (int i = 0; i <= maxa; i++)
    {
        for (int j = 0; j <= maxb; j++)
        {
            if(4*i + 7*j == n) exists = true;
        }
    }
    
    if(exists) cout << "Yes" << endl;
    else cout << "No" << endl;
        
    
    return 0;
}
