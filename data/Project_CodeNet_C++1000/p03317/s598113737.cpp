#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=0;i<n;i++)
#define endl   "\n"
int sum(int n)
{
    if(n==0) return  0;

    return n%10+ sum((n/10));




}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 int n,k;
 cin>>n>>k;
 vector<int> v(n);
 f(n)cin>>v[i];
 
 int operation=1;
 int i=k;
 while(i<n)
 {
    i+=k-1;
    operation++;


 }
 cout<<operation<<endl;






}