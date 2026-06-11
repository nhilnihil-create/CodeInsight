#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#include <iostream>
#define fastinput ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int main()
{    
    fastinput;
    LL n,i,j,k,t,temp;
    cin>>n>>k;
    LL ans=0;
    map<LL,LL> freq;
    freq[0]++;
    LL sum=0;
    for(i=0;i<n;i++)
    {
        cin>>j;        
        sum+=j;
        ans+=freq[sum%k]; 
        freq[sum%k]++; 
        
    }
    cout<<ans<<endl;
    return 0;
}

