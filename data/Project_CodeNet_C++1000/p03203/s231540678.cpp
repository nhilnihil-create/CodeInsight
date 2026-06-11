#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
typedef struct aaaaa{
  int x,y,t;
}Grid;
using namespace std;
int main(){
  int h,w,n;cin>>h>>w>>n;
  vector<pair<int,int> > pii;
  for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    if(a>=b)
      pii.pb(mp(a,b));
  }
  sort(ALL(pii));
  int po=0;
  for(int i=0;i<pii.size();i++){
    if(pii[i].S<pii[i].F-po){
      cout<<pii[i].F-1<<endl;
      return 0;
    }else if(pii[i].S==pii[i].F-po){
      po++;
    }
  }
  cout<<h<<endl;
  return 0;
}
