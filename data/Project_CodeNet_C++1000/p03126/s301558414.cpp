#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() {
   int n,m;
  cin>>n>>m;
  int ans=0;
  
    bool ok=true;
  vector<set<int>> a(n);
    rep(i,n){
    		int k;
   			 cin>>k;
      //cout<<k<<endl;
      rep(j,k){
        int c;
    	 cin>>c;
        a[i].insert(c);
      }
    }
  /////////////////
 for(int i=1;i<=m;i++){
   ok=true;
      rep(j,n){
    	 if(!(a[j].count(i))){
     	    ok=false;
         }
        //cout<<j<<endl;
      }
    if(ok) ans++;
  }
  cout<<ans<<endl;
}