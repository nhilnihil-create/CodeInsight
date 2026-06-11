#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int l;
  cin>>l;
  int n=0;
  rep(bit,25){
    if(l&(1<<bit))n=max(n,bit+1);
  }
  vector<int>u,v,w;
  rep(i,n-1){
    u.push_back(i);
    v.push_back(i+1);
    w.push_back(0);
    u.push_back(i);
    v.push_back(i+1);
    w.push_back(1<<i);
  }
  int x=1<<(n-1);
  rep(bit,n-1){
    if(l&(1<<bit)){
      u.push_back(bit);
      v.push_back(n-1);
      w.push_back(x);
      x+=(1<<bit);
    }
  }
  int m=u.size();
  cout<<n<<" "<<m<<endl;
  rep(i,m){
    cout<<u[i]+1<<" "<<v[i]+1<<" "<<w[i]<<endl;
  }
}