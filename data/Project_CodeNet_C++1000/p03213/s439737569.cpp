#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int ans=0;
llint n;
vector<int>v;

map<llint,llint> factorize(int x){
  map<llint,llint>ret;
  int t=x;
  for(int i=2;i*i<=x;i++){
    while(t%i==0){
      t/=i;
      ret[i]++;
    }
  }
  if(t>1)ret[t]++;
  return ret;
}


void solve(){
  cin >> n;
  map<llint,llint>mp;
  int ans=0;
  vector<llint>cnt(105,0);
  for(int i=1;i<=n;i++){
    for(auto p:factorize(i)){
      cnt[p.first]+=p.second;
    }
  }
  for(int i=2;i<105;i++){
    if(cnt[i]>=74)ans++;
  }
  for(int i=2;i<105;i++){
    for(int j=2;j<105;j++){
      if(i!=j && cnt[i]>=2 && cnt[j]>=24)ans++;
    }
  }
  for(int i=2;i<105;i++){
    for(int j=2;j<105;j++){
      if(i!=j && cnt[i]>=4 && cnt[j]>=14)ans++;
    }
  }
  for(int i=2;i<105;i++){
    for(int j=2;j<105;j++){
      for(int k=2;k<j;k++){
        if(i!=j && i!=k && cnt[i]>=2 && cnt[j]>=4 && cnt[k]>=4)ans++;
      }
    }
  }
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
