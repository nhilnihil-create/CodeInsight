#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    int a[m];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    sort(a ,a+m);
    int temp = lower_bound(a,a+m,x) - a ;
    int temp2 = m - temp;
    cout<<min( temp , temp2);
}