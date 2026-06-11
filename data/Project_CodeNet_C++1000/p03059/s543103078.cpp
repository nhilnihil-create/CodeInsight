#include<bits/stdc++.h>
using namespace std;
int  main()

{
    int a,b,res=0,p=1,q=0;
    float t;
    cin>>a>>b>>t;
    while(a*p<=(t+0.5))
    {
        p++;
        res+=b;
    }
    cout<<res<<endl;
    return 0;
}
