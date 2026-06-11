#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=0;i<n;i++)
#define endl   "\n"
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     int d,n;
     cin>>d>>n;
     if(d==0)
     {
         if(n==100) cout<<101<<endl;
         else cout<<n<<endl;


     }
    if(d==1)
    {
        if(n==100) cout<<10100<<endl;
        else cout<<n*100<<endl;


    }
    if(d==2)
    {
        if(n==100) cout<<1010000<<endl;
        else cout<<n*10000<<endl;


    }


}