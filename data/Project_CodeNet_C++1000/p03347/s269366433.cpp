#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll cnt;
ll a[200010];
ll ch;
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]-a[i-1]<=1){
        ch++;
        }
    }
    if(a[0]==0&&ch==n)
    {
        for(int i=0; i<n; i++)
        {
            if(a[i-1]<a[i]){
            cnt+=abs(a[i]-a[i-1]);
            }else{
            cnt+=a[i];
            }
        }
        cout<<cnt;
    }
    else
    {
        cout<<-1;
    }
}
