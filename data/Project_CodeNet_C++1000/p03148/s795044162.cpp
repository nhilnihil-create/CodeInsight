#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<cstdlib>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;

int main(){
  int n, k;cin>>n>>k;
  vector<P> sushi(n);
  rep(i, n){
    int t, d;cin>>t>>d;
    sushi[i]=P(d, --t);
  }
  sort(sushi.begin(), sushi.end(), greater<P>());
  vector<bool> include(n, false);
  vector<int> selected;
  ll kind=0LL;
  ll sum=0LL;
  rep(i, k){
    P p=sushi[i];
    if(!include[p.second]){
      include[p.second]=true;
      kind++;
    }else{
      selected.push_back(p.first);
    }
    sum += p.first;
  }
  sort(selected.begin(), selected.end(), greater<int>());
  ll ans=sum+kind*kind;
  ll id=(ll)kind;
  while(!selected.empty() && id<n){
    if(include[sushi[id].second]){id++;continue;}
    include[sushi[id].second] = true;
    sum -= selected.back();selected.pop_back();
    sum += sushi[id].first;
    id++;kind++;
    ans = max(ans, sum+kind*kind);
  }
  cout<<ans<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
