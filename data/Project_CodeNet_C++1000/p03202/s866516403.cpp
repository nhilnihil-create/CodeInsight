#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<int>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<61;
const ll mod=1e9+7;

int main(){
  int i,j;
  int n;
  cin>>n;
  int a[n];
  bool ok=1;
  for(i=0;i<n;i++){
    cin>>a[i];
    if(i>=1&&a[i-1]>=a[i]) ok=0;
  }
  if(ok){
    cout<<1<<endl;
    return 0;
  }
  
  int l=1,r=202020;
  while(r-l>1){
    int mid=(r+l)/2;
    map<int,int> m;
    bool ng=0;
    for(i=1;i<n;i++){
      if(ng==1) break;
      if(a[i-1]==a[i]){
        m[a[i]]++;
        int u=a[i];
        while(m[u]==mid){
          m.erase(u);
          u--;
          if(u<=0){
            ng=1;
            break;
          }
          m[u]++;
        }
      }
      else if(a[i-1]>a[i]){
        auto it=m.rbegin();
        while(it!=m.rend()&&it->first>a[i]){
          m.erase(it->first);
        }
        m[a[i]]++;
        int u=a[i];
        while(m[u]==mid){
          m.erase(u);
          u--;
          if(u<=0){
            ng=1;
            break;
          }
          m[u]++;
        }
      }
    }
    if(ng==1) l=mid;
    else r=mid; 
  }
  cout<<r<<endl;

  
  return 0;
}