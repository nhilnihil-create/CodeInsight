#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
      int n; cin>>n;
      vector<vector<int>> info(n-1,vector<int>(3,0));
      rep(i,0,n-1) cin>>info[i][0]>>info[i][1]>>info[i][2];
      rep(i,0,n-1){
            int time=info[i][1]+info[i][0];
            rep(j,i+1,n-1){
                  time=max(info[j][1],(int)ceil((double)time/info[j][2])*info[j][2])+info[j][0];
            }
      cout<<time<<endl;
      }
      cout<<0<<endl;
}