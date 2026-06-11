#include<bits/stdc++.h>
using namespace std;
main()
{
    int a,b[100],Max=0,Min=0,i;
    cin>>a;
    for(i=0;i<a;i++)
    {
        cin>>b[i];
        if(b[i]>Max)
            Max=b[i];
    }
    Min=b[0];
    for(i=0;i<a;i++)
    {
        if(Min>b[i])
            Min=b[i];
    }
    cout<<(Max-Min)<<endl;
}
