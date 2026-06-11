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
  string s; cin>>s;
  int w; cin>>w;
  int n=s.size();
  for(int i=0;i<n;i+=w) {
    cout<<s[i];
  }
  cout<<endl;
}