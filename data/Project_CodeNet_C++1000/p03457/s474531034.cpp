#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int mt=0,mx=0,my=0;
    bool check = true;
    for(int i=0;i<N;i++)
    {
        int t,x,y;
        cin>>t>>x>>y;
        int tmpt=fabs(mt-t);
        int tmpx=fabs(mx-x);
        int tmpy=fabs(my-y);
        
        int zxy = (tmpx + tmpy)%2==0?2:1;
        int zt = tmpt%2==0?2:1;
        bool parity=(zxy!=zt);
        if(tmpt<tmpx+tmpy||tmpx==0&&tmpy==0)
        {
            cout<<"No"<<endl;
            check = false;
            break;
        }
        else if(parity)
        {
            cout<<"No"<<endl;
            check = false;
            break;        
        }
        mt=t;
        mx=x;
        my=y;
    }
    if(check)
    {
        cout<<"Yes"<<endl;
    }
}