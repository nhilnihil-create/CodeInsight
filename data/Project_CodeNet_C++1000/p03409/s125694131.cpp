#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;
using graph = vector<vector<char>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin>>N;
    vector<vector<int>> R(N,vector<int>(2)),B(N,vector<int>(2));
  	vector<int> g(2*N,-1);
    rep(i,N) cin>>R[i][0]>>R[i][1];
    rep(i,N) {
      cin>>B[i][0]>>B[i][1];
      g[B[i][1]]=B[i][0];
    }
    sort(R.begin(),R.end());
    reverse(R.begin(),R.end());
    int ans = 0;
    for(auto x:R){
        for(int i = x[1]+1; i < 2*N; i++){
          if(g[i]>x[0]) {
            ans++;
            g[i]=-1;
            break;
          }
        }
    }
    cout<<ans<<endl;
}