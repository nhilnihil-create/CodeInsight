#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    
    if(n%2==0)
        cout<<n;
    else
        cout<<2*n;
    return 0;
}
