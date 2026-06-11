
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,k;
cin>>n>>k;
int val=0;
for(int i=0;i<(1<<(n));i++)
{if(i!=k)
    val^=i;
}
if(val==k||k==0)
{
    if(k==0)
    {
        for(int i=0;i<(1<<(n));i++)
            cout<<i<<" "<<i<<" ";
    }
    else
    {
        cout<<k<<" ";
        for(int i=0;i<(1<<n);i++)
        {  if(i!=k)
            cout<<i<<" ";
        }
        cout<<k<<" ";
        for(int i=(1<<n)-1;i>=0;i--)
        {
            if(i!=k)
                cout<<i<<" ";
        }
        cout<<endl;
    }
}
else
    cout<<-1<<endl;
    return 0;
}
