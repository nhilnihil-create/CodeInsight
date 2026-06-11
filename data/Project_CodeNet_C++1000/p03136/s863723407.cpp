#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,b,a)     for(int i=b;i>=a;i--)

int n,temp,sum=0,maxi;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    cin>>n;
    rep(i,1,n)
    {
        cin>>temp;
        if(i==1)
            maxi=temp;
        else
            if(temp>=maxi)
                maxi=temp;
        sum+=temp;
    }
    sum-=maxi;
    if(sum>maxi)
        cout<<"Yes";
    else
        cout<<"No";
}

