#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,b,a)     for(int i=b;i>=a;i--)

int n,m,arr[32],temp,cnt=0,k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    cin>>n>>m;
    rep(i,1,n)
    {
        cin>>k;
        rep(j,1,k)
            {
                cin>>temp;
                arr[temp]++;
            }
    }
    rep(i,1,m)
        if(arr[i]==n)
            cnt++;
    cout<<cnt;
}

