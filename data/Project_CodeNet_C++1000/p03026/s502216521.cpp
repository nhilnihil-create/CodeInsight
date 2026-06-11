#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>a(N-1),b(N-1);
  for(int i=0;i<N-1;i++)cin>>a[i]>>b[i];
  for(int i=0;i<N-1;i++)a[i]--,b[i]--;
  vector<int>c(N);
  for(int i=0;i<N;i++)cin>>c[i];
  sort(rng(c));
  vector<set<int>>v(N);
  for(int i=0;i<N-1;i++){
    v[a[i]].insert(b[i]);
    v[b[i]].insert(a[i]);
  }
  vector<int>ans(N);
  queue<int>q;
  for(int i=0;i<N;i++)if(v[i].size()==1)q.push(i);
  int cnt=0;
  while(q.size()){
    int now=q.front();
    q.pop();
    ans[now]=c[cnt];
    cnt++;
    for(auto it:v[now]){
      v[it].erase(now);
      if(v[it].size()==1)q.push(it);
    }
  }
  ll sum=0;
  for(int i=0;i<N-1;i++)sum+=min(ans[a[i]],ans[b[i]]);
  cout<<sum<<endl;
  for(auto it:ans)cout<<it<<" ";
  cout<<endl;
  return 0;
}
