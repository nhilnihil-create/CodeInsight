#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MOD 1000000007
#define INF 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define req(i, j, n) for(int i = j; i <= (int)(n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int pw2(int n){
  int t=1;
  while(t<=n){
    t*=2;}
  return t;
}

int main() {
  int n;
  cin>>n;
  
  map<int, int> nu;
  
  for(int i=1;i<=n;i++){
   int a;
    cin>>a;
    if(nu.find(a)==nu.end())
      nu[a]=0;
    ++nu[a];
  }
  
 
  
  
  int ans=0;
  for(auto itr=nu.rbegin();itr!=nu.rend();itr++){
    int b=itr->first;
    int p=pw2(b)-b;
    
    
    if(b==p){
      ans+=nu[b]/2;}
    else{
      if(nu.find(p) == nu.end())continue;
      ans+=min(nu[b], nu[p]);
      nu[p]-=min(nu[b], nu[p]);
    }
  }
  
  cout<<ans<<endl;
  
  
  
  
  
  


}