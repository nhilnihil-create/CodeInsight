#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem(arr,v) memset(arr,v,sizeof(arr))
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     ll t,kk=INT_MAX,v,mn,sum=0;
     for(int i=0;i<5;i++)
     {
         cin>>v;
         mn=v%10;
         if(mn<kk && mn!=0)
            kk=mn;
         if(v%10!=0)
         v=((v/10)+1)*10;
         sum+=v;
     }
     if(kk==INT_MAX)
        cout<<sum<<endl;
     else
     cout<<sum-(10-kk)<<endl;
}
