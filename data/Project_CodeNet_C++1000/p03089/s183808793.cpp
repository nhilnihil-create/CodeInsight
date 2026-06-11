#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n;
  cin>>n;
  vector<int> b(n),a(n);
  rep(i,n) cin>>b[i];
  bool ok=1;
  int tmp=0;
  while(!b.empty()){
    bool k=0;
    for(int j=b.size()-1; j>=0; j--){
      if(j+1==b[j]){
        a[tmp]=b[j]; tmp++;
        b.erase(b.begin()+j);
        k=1;
        break;
      }
    }
        
    if(!k){
      ok=0; break;
    }
  }
  if(ok){
    reverse(a.begin(),a.end());
    rep(i,n) cout<<a[i]<<endl;
  }else cout<<-1<<endl;
}