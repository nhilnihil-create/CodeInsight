#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define MAX 200005
#define INF 1001001001

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int d, g;
  cin >> d >> g;
  vector<int> p(d);
  vector<int> c(d);
  rep(i, d){
    cin >> p[i] >> c[i];
  }


  priority_queue<ll> PQ;
  for(int bit=0; bit< (1<<d); bit++){
    vector<bool> uncomplete(d);
    ll sum=0;
    ll ans=0;
    rep(i, d){
      if(bit&(1<<i)){
        sum+=c[i]+p[i]*100*(i+1);
        ans+=p[i];
      } else {
        uncomplete[i]=true;
      }
    }
    int j=d-1;
    for(int j=d-1; j>=0 && sum<g; j--){
      if(uncomplete[j]){
        int num=(g-sum-100)/(100*(j+1))+1;
        if(num<=p[j]-1){
          ans+=num;
          sum+=100*(j+1)*num;
          break;
        } else {
          ans+=p[j]-1;
          sum+=100*(j+1)*(p[j]-1);
        }
      }
    }
    if(sum<g)continue;
    PQ.push(-ans);
  }
  cout << -PQ.top() << endl;
  return 0;
}
