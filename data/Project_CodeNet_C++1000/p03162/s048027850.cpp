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
  ll n;
  cin>>n;
  ll a[n],b[n],c[n];
  ll i;
  for(i=0;i<n;i++)
  {
     cin>>a[i]>>b[i]>>c[i];
  }
  ll dp[n+1][3];
  dp[1][0]=a[0];
  dp[1][1]=b[0];
  dp[1][2]=c[0];
  for(i=2;i<=n;i++)
  {
    dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i-1];
    dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b[i-1];
    dp[i][2]=max(dp[i-1][1],dp[i-1][0])+c[i-1];
  }
  ll mx=max(dp[n][0],max(dp[n][1],dp[n][2]));
  cout<<mx;

}