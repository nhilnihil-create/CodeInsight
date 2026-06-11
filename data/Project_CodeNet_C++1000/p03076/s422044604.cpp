#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define MIN 100000
using namespace std;
int main()
{
    int a[6];
    int flag=0,ans;
    for(int i=1; i<6; i++)
    {
        cin>>a[i];
        if(i>1)if(a[i]!=a[i-1])flag=1;
    }
    if(!flag)
    {
        if(a[1]%10==0){
            cout<<a[1]*5<<endl;
        }
        else
        {
            int rem=a[1]%10;
            int add=10-rem;
            a[1]=a[1]+add;
            int m=a[1]*4;
            ans=m+a[2];
            cout<<ans;
            return 0;
        }
    }

    else if(flag)
    {
        int sum=0,ANS = MIN;
        for(int turn=1; turn<6; turn++)
        {
            swap(a[turn],a[5]);
            for(int i=1; i<5; i++)
            {
                int n=a[i];
                if(n%10==0)sum+=n;
                else{
                    int rem=n%10;
                    int add=10-rem;
                    n=n+add;
                    sum+=n;
                }
            }
            sum+=a[5];
            //cout<<sum<<endl;
            ANS=min(ANS,sum);
            swap(a[turn],a[5]);
            sum=0;
        }
        cout<<ANS<<endl;
    }
    return 0;
}
