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
 string user;
 cin>>user;
 int val=0;
 for(auto x:user)
 {
     if(x=='+') val++;
     else val--;


 }
 cout<<val<<endl;






}