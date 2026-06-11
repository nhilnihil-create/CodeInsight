#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,x;
    cin>>n>>x;

    vector<int> a(n);

    for(int i=0;i<n;i++)cin>>a[i];

    sort(a.begin(),a.end());

    int cnt=0;

    for(int i=0;i<n;i++)
    {
        x-=a[i];
        if(x<0)break;
        cnt++;
    }
    if(x>0)cnt--;

    cout<<cnt<<"\n";

    return 0;
}
