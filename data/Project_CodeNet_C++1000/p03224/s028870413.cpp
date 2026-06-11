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
const ll M = 998244353;
void add(ll& x, ll y) {x+=y; x%=M;}
void chmax(ll& x, ll y) {if (x<y) x=y;}
const int up[]={1,-1,0,0}, lf[]={0,0,1,-1};
bool vaild(int x, int y, int hh, int ww){return 0<=x&&x<hh&&0<=y&&y<ww;}

int main() {
  int n; cin>>n;
  if (n==1) {
    cout<<"Yes\n2\n1 1\n1 1"<<endl;
    return 0;
  }
  int p=0;
  while(n > p*(p+1)/2) p++;
  if (n != p*(p+1)/2) {
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  cout<<p+1<<endl;
  int d[p+2]; int id=0, nw=1;
  for(int i=0;i<=p;i++) {
    cout<<p<<" ";
    for(int j=0;j<id;j++) {
      cout<<d[j]++<<" ";
    }
    d[id]=nw;
    for(int j=id;j<p;j++) {
      cout<<nw++<<" ";
    }
    id++;
    cout<<endl;
  }
}