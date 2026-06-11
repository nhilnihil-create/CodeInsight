#include<iostream>
#include <bits/stdc++.h>

using namespace std;

long long ans;

int main()
{
    int n,k,i,num=0,sum=0;
    cin >> n >> k;
    for(i=1; i<=n; i++)
    {
        if(i%k==0) num++;
        else if(2*i%k==0) sum++;
    }
    ans=1ll*num*num*num;
    ans+=1ll*sum*sum*sum;
    cout << ans << endl;
    return 0;
}