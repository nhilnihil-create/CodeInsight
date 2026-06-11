#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,P>
using namespace std;
const int match[10]={0,2,5,5,4,5,6,3,7,6};

int main(){
   int n,m; cin >> n >> m;
   vector<int> a(m);
   vector<int> dp(10005,-INF);
   rep(i,m) cin >> a[i];
   sort(all(a));
   reverse(all(a));
   dp[0]=0;
   for(int i=1; i<=n; i++){
       rep(j,a.size()){
           if(i-match[a[j]]<0) continue;
           dp[i]=max(dp[i-match[a[j]]]+1,dp[i]);
       }
   }
   int num=n;
   while(num>0){
       rep(j,a.size()){
           if(num-match[a[j]]<0) continue;
           if(dp[num-match[a[j]]]==dp[num]-1){
               printf("%d",a[j]);
               num-=match[a[j]];
               break;
           }
       }
   }
return 0;
}
