#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <functional>
#include <set>
#define DB cerr<<"D"<<endl
#define pb push_back
using namespace std; using ll=long long; using ld=long double; const int INF=1e9; const ll LINF=1e18; const double dINF = 1e18; const ld ldINF = 1e18; const double EPS = 1e-6;
template<typename T, typename U, typename O> void caut(T a, U b, O c){cout<<"("<<a<<","<<b<<","<<c<<") ";} template<typename T, typename U> void caut(T a, U b){cout<<"("<<a<<","<<b<<") ";} template<typename T> void caut(T a){cout<<"("<<a<<") ";}
using P=pair<double,int>;
const ll M = 1e9+7;
void add(ll& x, ll y) {x+=y; x%=M;}
void chmax(ll& x, ll y) {if (x<y) x=y;}

int main() {
  int v[4]={};
  for(int i=0;i<3;i++) {
    int a,b; cin>>a>>b; a--; b--;
    v[a]++; v[b]++;
  }
  int o=0,t=0;
  for(int i=0;i<4;i++) {
    if (v[i]==1) o++;
    if (v[i]==2) t++;
  }
  if (o==2&&t==2) {
    cout<<"YES"<<endl;
  } else {
    cout<<"NO"<<endl;
  }
}