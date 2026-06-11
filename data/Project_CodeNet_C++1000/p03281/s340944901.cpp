#include <iostream>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
typedef long long int ll;
int main()
{
    int n;
    cin >>n;
    int count=0;
    rep(x,n+1)
    {
        if(x==0)continue;
        int cnt=0;
        if(x%2==0)continue;
        rep(i,x+1)
        {   
            if(i==0)continue;
            if(x%i==0)
            {
                cnt++;
               
            }
               
        }
        if(cnt==8)count++;
    }
    printf("%d",count);
}
