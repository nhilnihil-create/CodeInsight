#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[6],i,minn=9,chk,c,ans=0;
    for(i=0;i<5;i++){
        cin>>a[i];
    }
    for(i=0;i<5;i++){
        chk=a[i]%10;
        if(chk!=0 && chk<minn){
            minn=chk;
            c=i;
        }
    }
    for(i=0;i<5;i++){
        if(i!=c){
            ans+=(a[i]+9)/10*10;
        }
    }
    cout<<ans+a[c];
    return 0;
}
