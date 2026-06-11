#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0)
#define infl 1e18+9
#define sz(a) ((int)a.size())
ll mod=1e9+7;

struct S{
  int w,s,v; 
  void read(){
    cin>>w>>s>>v; 
  }
  bool operator<(const S &a){
    return w+s < a.w+a.s ; 
  }
};

void solve(){
  int n; cin>>n; 
  vector<S> v(n); 
  for(int i=0;i<n;i++){
    v[i].read(); 
  }
  sort(v.begin(),v.end()); 
  vector<ll> best(1e4+5,-1); 
  best[0]=0; 
  ll ans=0; 
  for(int i=0;i<n;i++){
    for(int j=0;j<=v[i].s;j++){
      ans=max(ans,best[j]+v[i].v); 
    }
    for(int j=v[i].s;j>=0;j--){
      if(j+v[i].w<1e4+5 && best[j]>=0){
        best[j+v[i].w]=max(best[j+v[i].w],best[j]+v[i].v); 
      }
    }
  }
  cout<<ans<<endl;
}

int main(){
	fast_io;
	clock_t beg=clock();
  int t;
  t=1;
  while(t--){
	  solve();
  }
	clock_t end=clock();
	fprintf(stderr,"%.2lf sec\n",(double)(end-beg)/CLOCKS_PER_SEC);
	return 0;
}