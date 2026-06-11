#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define s second
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
const ll N=1e5+5;
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
  ll n,j,k;
  cin>>n>>k;
  ll a[n+1];
  ll i;
  for(i=1;i<=n;i++)
      cin>>a[i];
    ll dp[n+1];
   dp[1]=0;
  dp[2]=abs(a[2]-a[1]);
  for(i=3;i<=n;i++)
  {
     ll temp=max(1LL,i-k);
     dp[i]=INT_MAX;
     for(j=i-1;j>=temp;j--)
        dp[i]=min(dp[i],dp[j]+abs(a[j]-a[i]));
  }
  cout<<dp[n];

}