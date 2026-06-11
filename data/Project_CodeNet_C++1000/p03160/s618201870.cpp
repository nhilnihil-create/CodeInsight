#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
const int INF = 1e9 + 7;
     
int main(){
      IOS;
      int N;
      cin>>N;
      std::vector<int> h, dp;
      for(int i=0;i<N;i++){
            int input;
            cin>>input;
            h.pb(input);
            dp.pb(0);
      }
      dp[0] = 0;
      dp[1] = abs(h[1]-h[0]);
      for(int i=2;i<N;i++){
            dp[i] = min(abs(h[i] - h[i-1]) + dp[i-1], abs(h[i] - h[i-2]) + dp[i-2]);
            // cout<<dp[i]<<" ";
      }
      cout<<dp[N-1];
      return 0;
}