#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> T(N);
  vector<int> max_V(N+2);
  rep(i,N) cin >> T[i];
  max_V[0]=0;
  rep(i,N) cin >> max_V[i+1];
  max_V.pb(0);
  double ans=0;
  int sumT=0;
  rep(i,N) sumT += T[i];

  vector<int> T_;
  T_.pb(0);
  int tt = 0;
  for(int i=0;i<N;i++){
    tt += T[i];
    T_.pb(tt);
  }

  vector<double> time(sumT*2+1);
  vector<double> v(sumT*2+1,0);
  double t=0;
  for(int i=0;i<(int)time.size();i++){
    time[i] = t;
    t += 0.5;
  }
  v[0] = 0;
  for(int i=1;i<(int)time.size();i++){
    for(int j=1;j<=N;j++){
      if(T_[j-1] <= time[i] && time[i] < T_[j]){
        v[i] = max_V[j];
      }
    }
  }

  for(int i=0;i<(int)T_.size();i++){
    for(int j=0;j<(int)time.size();j++){
      if(time[j] >= (double)T_[i]){
        v[j] = min(v[j], (double)max_V[i]+(time[j]-(double)T_[i]));
      }
      if(time[j] <= (double)T_[i]){
        v[j] = min(v[j], (double)max_V[i+1]+((double)T_[i]-time[j]));
      }
    }
  }
  for(int i=0;i<(int)time.size();i++){
    //cout << time[i] << '\t' << v[i] << endl;
  }
  for(int i=1;i<(int)v.size();i++){
    ans += (v[i]+v[i-1])/4;
  }

  cout << setprecision(10)<<ans << endl;
  return 0;
}
