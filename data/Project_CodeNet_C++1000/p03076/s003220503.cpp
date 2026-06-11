#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[5]={},sum=0,m=0;
    for(int i=0;i<5;i++)
        {
            cin>>a[i];
            sum+=((a[i]+9)/10 * 10);
            m = max(m,(((a[i]+9)/10 * 10)-a[i]));
        }
    cout<<sum-m;
    return 0;
}

