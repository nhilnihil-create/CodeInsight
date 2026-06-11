#include<bits/stdc++.h>
using namespace std;
#define rep(i ,a, n) for (long long int i=a;i<=n;i++)
#define pb  push_back
#define mp make_pair
#define fp first
#define sp second
#define be(v) v.begin(),v.end()
typedef long long ll;
typedef vector<ll> vi ;
typedef vector<pair<ll , ll > >  vpi ;
const int ma1=1e5+5;
string no="NO",yes="YES";
#define MOD 1000000007
int max_char=26;


int main()
{
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;

    while(t--)
    {
         ll n,m;
         cin>>n>>m;
         ll a[n+1];
         for(int i=1;i<=n;i++)
            cin>>a[i];
         ll dp[100005]={0};
         for(int i=0;i<=m;i++)
         {
             bool flag=0;
             for(int j=1;j<=n;j++)
             {
                 if(i-a[j]>=0 && !dp[i-a[j]])
                    flag=1;
             }
             dp[i]=flag;
         }
         if(dp[m])
         {
             cout<<"First";
         }
         else cout<<"Second";
    }
    return 0;
}














