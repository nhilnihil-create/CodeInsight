#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define s second
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
const ll N=1e3+5;
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
ll dp[N][N];
int main() {
FIO;
  ll n;
  cin>>n;
  double p[n];
  ll i,j;
  for(i=0;i<n;i++)
    cin>>p[i];
  double dp[n+1][n+1];
  dp[0][0]=1.0;
  for(i=0;i<=n;i++)
  {
     for(j=0;j<=n;j++)
     {
        if(i==0 && j==0)
          continue;
        if(i==0)
          dp[i][j]=0.0;
        else if(j==0)
          dp[i][j]=(1.0-p[i-1])*dp[i-1][j];
        else
          dp[i][j]=p[i-1]*dp[i-1][j-1]+(1.0-p[i-1])*dp[i-1][j];
        //cout<<dp[i][j]<<endl;
     }
  }
  double ans=0.0;
  for(i=n/2+1;i<=n;i++)
  {
     if(2*i>n)
      ans+=dp[n][i];
  }
   cout<<fixed<<setprecision(10);
  cout<<ans;
}