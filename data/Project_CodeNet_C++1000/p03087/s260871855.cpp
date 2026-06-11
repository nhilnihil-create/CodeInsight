#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define w(x) scanf("%d",&x);while(x--)
#define rep(i,a,b) for(i=a;i<=b;i++)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 2*acos(0.0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

long long int mod=1e9+9;
const int N=100000;
int t,i,j,cs=0,n,m,a,q,b;
string s;

int main()
{
   cin>>n>>q>>s;

   int ans[n+1]={};
   for(i=1;i<n;i++){
       ans[i+1]=ans[i];
    if(s[i-1]=='A' && s[i]=='C')
        ans[i+1]++;
   }
   //for(auto it: ans) cout<<it<<" ";
   while(q--){
    cin>>a>>b;
    cout<<ans[b]-ans[a]<<endl;
   }
}




