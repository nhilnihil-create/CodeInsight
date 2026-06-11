#include<bits/stdc++.h>

using namespace std;

int main()
{
        int n,t,c1,t1,i,k=0,d[1000]={0},p[1000];
        cin>>n>>t;
        for(i=0;i<n;i++)
        {
                cin>>c1>>t1;
                if(t1<=t)
                {
                     p[k]=t1;
                     d[k]=c1;
                     k++;
                }
        }
        sort(d,d+k);
        if(d[0]>0)
        cout<<d[0]<<endl;
        else
                cout<<"TLE"<<endl;
        return 0;
}
