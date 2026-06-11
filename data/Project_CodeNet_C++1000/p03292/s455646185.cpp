#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5],ans;
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    ans=0+abs(a[0]-a[1])+abs(a[1]-a[2]);
    cout<<ans;
    return 0;

}
