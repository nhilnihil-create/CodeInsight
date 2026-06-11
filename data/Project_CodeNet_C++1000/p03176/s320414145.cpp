#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define mod 1000000007
class flow
{public:
ll int he;
ll int be;
    
};
ll int solve(flow* a,ll int n)
{ll int dp[n]={0};
ll int ans=0;
//cout<<a[0].he<<" "<<a[0].be<<" poi\n";
map<ll int,ll int> meaningful;
meaningful[a[0].he]=a[0].be;
dp[0]=a[0].be;
ans=max(ans,dp[0]);
//cout<<dp[0]<<" dp[0]\n";
for(ll int i=1;i<n;i++)
{dp[i]=a[i].be;
auto it=meaningful.lower_bound(a[i].he+1);
if(it!=meaningful.begin())
{it--;

dp[i]=dp[i]+it->second;    
}
meaningful[a[i].he]=dp[i];
it=meaningful.upper_bound(a[i].he);
while(it!=meaningful.end()&&it->second<=dp[i])
{auto temp=it;
temp++;
meaningful.erase(it);
it=temp;
    
}

ans=max(ans,dp[i]) ;   

//cout<<i<<" "<<dp[i]<<endl;    
}
return ans;

}

int main()
{ll int n;
cin>>n;
 flow a[n];
 for(ll int i=0;i<n;i++)
 {cin>>a[i].he;}
  for(ll int i=0;i<n;i++)
 {cin>>a[i].be;}
 
  ll int d=solve(a,n);
cout<<d<<endl;    
}