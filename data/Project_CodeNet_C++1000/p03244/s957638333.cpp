#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;

int main(){
  int n;
  cin >> n;
  map<int, int> mpo, mpe;
  rep(i, n/2){
    int a, b;
    cin >> a >> b;
    mpo[a]++;
    mpe[b]++;
  }
  P omax = P(-1, 0), osndmax = P(-1, 0), emax = P(0, 0), esndmax = P(0, 0);
  for(P x : mpo){
    if(x.second >= omax.second){
      osndmax = omax;
      omax = x;
    }else if(x.second > osndmax.second){
      osndmax = x;
    }
  }
  for(P x : mpe){
    if(x.second >= emax.second){
      esndmax = emax;
      emax = x;
    }else if(x.second > esndmax.second){
      esndmax = x;
    }
  }
  int ans = 0;
  if(omax.first == emax.first){
    ans = min(n - omax.second - esndmax.second, n - emax.second - osndmax.second);
  }else{
    ans = n - omax.second - emax.second;
  }
  cout << ans <<endl;
}