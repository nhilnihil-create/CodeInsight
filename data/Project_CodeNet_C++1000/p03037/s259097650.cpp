#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n, m, l[100005], r[100005], i, j, a, b;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>l[i]>>r[i];
    }
    sort(l, l+m);
    sort(r, r+m);
    b=r[0]-l[m-1];
    if(b<0)
    {
        a=0;
    }
    else
    {
        a=b+1;
    }
    cout<<a;
    return 0;
}