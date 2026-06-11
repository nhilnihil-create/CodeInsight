#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,w,h,cnt=0;
    cin>>n>>w>>h;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if((x>=w)&&(y>=h))
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
