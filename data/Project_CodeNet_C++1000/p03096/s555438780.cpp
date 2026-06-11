#include<bits/stdc++.h>
#define MOD 1e9+7
using namespace std;
#define  pp push_back
#define  po pop_back
#define  mp make_pair
#define clr(a) memset(a,0,sizeof(a))
#define neg(a) memset(a,-1,sizeof(a))
#define fas(a) memset(a,false,sizeof(a))
#define debug(x) cout<<#x<<": "<<x<<endl
#define debug1(x) cout<<#x<<": "<<x<<" "
#define rev(x) reverse(x.begin(), x.end())
#define int long long 
#define F first
#define S second
//int a[2000];
void printvector(std::vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void printarray(int a[],int n){for (int i = 0; i < n; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
 
 

 

void  solve()
{
  int n;cin>>n;
  int a[n];
  for(int i=0;i<n;i++){cin>>a[i];a[i]--;};
  map<int,int> m;
  int next[n];
  for(int i=n-1;i>=0;i--)
  {
      if(m.find(a[i])!=m.end())
      {
        next[i]=m[a[i]];
      }
      else
      {
         next[i]=n;
      }
      m[a[i]]=i;
  }

  // printarray(a,n);
  // printarray(next,n); 

  int mod=MOD;
  int no[n];
  for(int i=n-1;i>=0;i--)
  {
      if(i==n-1)
      {
         no[i]=1;
      }
      else
      {
        no[i]=no[i+1];
        int x=next[i];
        if(x!=i+1&&x!=n)
        {
           no[i]+=no[x];no[i]%=mod;
        }
      }
  }
  
  // printarray(a,n);
  // printarray(no,n);

  cout<<no[0]<<endl;





}




 int32_t main() 
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    
   solve();

return 0;

}