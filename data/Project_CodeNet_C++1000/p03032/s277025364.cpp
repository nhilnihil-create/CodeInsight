#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> v(n),vcopy(n);

  for(int i=0;i<n;++i){
    cin >> v[i];
    vcopy[i]=v[i];
  }
  int r=min(n,k);
  vector<ll> a(n+1),b(n+1);
  a[0]=0;
  for(int i=0;i<n;++i){
    a[i+1]=a[i]+v[i];
    //cout << a[i+1] << endl;
  }
  reverse(vcopy.begin(),vcopy.end());
  b[0]=0;
  for(int i=0;i<n;++i){
    b[i+1]=b[i]+vcopy[i];
    //cout << b[i+1] << endl;
  }
  int maxid;
  ll ans=0;
  for(int i=0;i<=r;++i){
    for(int x=0;x<=i;++x){
      int j=i-x;
      ll tmp=a[x]+b[j];
      //cout << a[x] << " " << b[j] << endl;
      //cout << tmp << endl;
      int K=k-i;
      priority_queue<int> que;
      for(int ai=0;ai<x;++ai){
        if(v[ai]<0) que.push(-v[ai]);
      }
      for(int bi=0;bi<j;++bi){
        if(vcopy[bi]<0) que.push(-vcopy[bi]);
      }
      for(int l=0;l<K;++l){
        if(que.size()){
          tmp+=que.top();
          que.pop();
        }
      }
      //cout << tmp << endl;
      ans=max(ans,tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
