#include <bits/stdc++.h>
#define rep(i, n) for(int i=0;i<int(n);++i)
using namespace std;
template<class A>void pr(A a){cout << a << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
int INF=numeric_limits<int>::max();
// for(int j=0;j<N;++j) {}

vector<int> par;
vector<int> ran;

void init(int n) {
  rep(i,n) {
    par.push_back(i);
    ran.push_back(0);
  }
}

int root(int n) {
  if(par[n]==n) return n;
  return par[n]=root(par[n]);
}

void unite(int x,int y) {
  x=root(x);
  y=root(y);
  if(ran[x]<ran[y]) {
    par[x]=y;
  } else {
    par[y]=x;
    if(ran[x]==ran[y]) ran[x]++;
  }
}

void coutAll(int n) {
  pr("par[i]","ran[i]");
  rep(i,n) {
    pr(par[i],ran[i]);
  }
}

int main(void) {
  int n,m;cin>>n>>m;
  vector<int> p(n);
  rep(i,n) cin>>p[i];
  vector<vector<int>> xy(n);
  int ans=0;

  init(n);

  int x,y;
  rep(i,m) {
    cin>>x>>y;
    --x;
    --y;
    unite(x,y);
    xy[x].push_back(y);
    xy[y].push_back(x);
  }

  // coutAll(n);

  rep(i,n) {
    if(root(i)==root(p[i]-1)) ans++;
    else if(i==p[i]-1) ans++;
    // pr(p[i],root(i),root(p[i]));
  }
  pr(ans);

  return 0;
}
