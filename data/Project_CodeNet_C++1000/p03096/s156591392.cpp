#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define INF 100000000000000000
#define modulo 1000000007
#define mod 998244353
#define int long long int
using namespace std;

int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
   //   freopen("q.gir","r",stdin);
   //   freopen("q.cik","w",stdout);
      int n;
      cin>>n;
      vector<int>arr;
      int prev=-INF;
      for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(prev!=x)arr.pb(x);
            prev=x;
      }
      n=arr.size();
      if(n==0){
            cout<<"WA\n";
            return 0;
      }
      vector<int>next(300000,INF);
      vector<int>data(300000,INF);

      for(int i=n-1;i>=0;i--){
            next[i]=data[arr[i]];
            data[arr[i]]=i;
      }
      vector<int>dp(300000,0);
      int pre=1;
      for(int i=0;i<n;i++){
            if(i>0){
                  dp[i]+=dp[i-1];
                  dp[i]%=modulo;
            }
            else dp[i]=1;
            if(next[i]<dp.size()){
                  dp[next[i]]+=dp[i];
                  dp[next[i]]%=modulo;
            }
      }
      cout<<dp[n-1];
}
