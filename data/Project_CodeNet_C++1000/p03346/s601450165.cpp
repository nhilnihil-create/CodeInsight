#include <bits/stdc++.h>
#define FLASH ios_base::sync_with_stdio(0);
#define ll long long
#define debt(x,y)cout<<"#x = "<<(x)<<" and "<<"#y = "<<(y)<<endl;
#define deb(x)cout<<"#x = "<<(x)<<endl;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define arr(a,n) for(ll i=1;i<=n;i++) cout<<a[i]<<" "; cout << "\n";
#define vecc(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" "; cout << "\n";


using namespace std;

ll massiv[200010];
ll dp[200010];
ll n;

int main(){
FLASH;
cin>>n;
ll maxx=0;
for(ll i=1;i<=n;i++)cin>>massiv[i];
for(ll i=1;i<=n;i++)
{
  dp[massiv[i]]=max(dp[massiv[i]-1]+1,dp[massiv[i]]);
  maxx=max(maxx,dp[massiv[i]]);  	
}

cout<<n-maxx<<endl;






return 0;
} 
