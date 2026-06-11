#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;

using namespace std;

int main() {
  ll n,m;
  cin>>n;
  vector<int> d(n);
  rep(i,n) cin>>d[i];
  cin>>m;
  vector<int> t(m);
  rep(i,m) cin>>t[i];
  bool ans=true;
  
  sort(all(d));
  sort(all(t));
  int st=0;
  rep(i,m){
   // cout<<t[i]<<endl;
    if(!ans) break;
    for(int j = st ; j < n ; j ++ ){
    	if(t[i]<d[j]) {
    		   ans=false;
    		  break;
          t[i]=-1;
   		}
        if(t[i]==d[j]){
          d[j]=-1;t[i]=-1;
          st=j+1;
         break; 
        }
    
    }
    if(t[i]!=-1){
      ans=false;
      break;
      }
    
  }
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}