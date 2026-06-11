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
      int N, K;
      cin>>N>>K;
      int h[N], dp[N];
      for(int i=0;i<N;i++){
            cin>>h[i];
      }
      dp[0] = 0;
      dp[1] = abs(h[1]-h[0]);
      for(int i=2;i<N;i++){
            int mini = INT_MAX, j = i-1, ctr = K;
            while(j >= 0 && ctr > 0){
                  int val = abs(h[i] - h[j]) + dp[j];
                  if(val < mini)
                        mini = val;
                  --j;
                  --ctr;
            }
            dp[i] = mini;
      }
      cout<<dp[N-1];
      return 0;
}