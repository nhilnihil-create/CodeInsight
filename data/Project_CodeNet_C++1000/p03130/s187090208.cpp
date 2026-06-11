#include <bits/stdc++.h>
using namespace std;

int main()
{


    int c1=0,c2=0,c3=0,c4=0;

    for(int i=0;i<3;i++){
        int ai,bi;
        cin>>ai>>bi;
        
        if(ai==1)
            c1++;
        else if(ai==2)
            c2++;
        else if(ai==3)
            c3++;
        else
            c4++;
        
        if(bi==1)
            c1++;
        else if(bi==2)
            c2++;
        else if(bi==3)
            c3++;
        else
            c4++;
        }


    if(max(max(max(c1,c2),c3),c4)>=3)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;

    return 0;
}
