#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define s second
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
const ll N=3005;
ll bexpo(ll x,ll n){
    if(n==0)return 1;
    else if(n%2==0)return bexpo(x*x,n/2);
    else return x*bexpo(x*x,(n-1)/2);
}
ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);} 
int Arr[N];
void initialize()
{
    for(int i = 0;i<N;i++)
    Arr[ i ] = i ;
}
int root(int i)
{
    while(Arr[ i ] != i)       
    {
     i = Arr[ i ];
    }
    return i;
}

void unio(int A ,int B)
{
    int root_A = root(A);       
    int root_B = root(B);  
    if(root_A<root_B)
        Arr[ root_A ] = root_B ;    
    else
        Arr[root_B]=root_A;
}
bool find(int A,int B)
{
    if( root(A)==root(B) )    
    return true;
    else
    return false;
}
int main() {
FIO;
  string s,t;
  cin>>s>>t;
  ll n=s.length();
  ll m=t.length();
  ll dp[n+1][m+1];
  ll i,j;
  for(i=0;i<=n;i++)
  {
     for(j=0;j<=m;j++)
     {
      if(i==0 || j==0)
          dp[i][j]=0;
      else if(s[i-1]==t[j-1])
          dp[i][j]=1+dp[i-1][j-1];
      else
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

     }
  }
  i=n;
  j=m;
  string ans="";
  while(i>0 && j>0)
  {
    if(dp[i][j]==dp[i-1][j])
        i-=1;
    else if(dp[i][j]==dp[i][j-1])
         j-=1;
    else
    {
      ans=s[i-1]+ans;
      i-=1;j-=1;
    }
  }
  cout<<ans;
}