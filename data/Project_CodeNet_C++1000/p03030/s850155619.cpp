#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define REP(i,m,n) for(ll i=(ll)(m); i<(ll)(n); ++i)
#define F first
#define S second
const double PI=acos(-1);
//fixed<<setprecision(11)<<

char in[120];
pair<pair<string,int>,int> p[110];
int main(){
  int a;cin>>a;
  rep(i,a){
  int t;cin>>in>>t;
  p[i]=make_pair(make_pair(in,-t),i);
  }
  sort(p,p+a);
  rep(i,a) cout<<p[i].second+1<<endl;
}