#include<bits/stdc++.h>
using namespace std; 
#define all(c) c.begin(),c.end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define tr(container,it) \
for(auto it=container.begin();it!=container.end();++it)
typedef long long ll ; 
typedef vector<int> vi;
#define mod 1000000007



int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
  //ios::sync_with_stdio(0);
// cin.tie(0);
/* int n;
cin>>n;
vector<array<int,2>>v(n);
REP(i,0,n-1)
cin>>v[i][0]>>v[i][1];
sort(all(v));
 */
int n;
cin>>n;
vector<double>dp(n+1);
dp[0]=1;
for(int i=0;i<n;++i){
  double p_head;
  cin>>p_head;
  for(int j=i+1;j>=0;--j){
    dp[j]=dp[j]*(1-p_head);
    if(j-1>=0)
    dp[j]+=dp[j-1]*p_head;
    
  }
}
double sum=0;
for(int i=n/2+1;i<=n;++i)
sum+=dp[i];
printf("%.10lf",sum);
    return 0;
}