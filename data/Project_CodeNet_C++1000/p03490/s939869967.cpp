#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; using ll=long long; using P=pair<ll,ll>; const int INF=1e9; const ll LNF=1e18;

int main(){
  string s; cin>>s; s+='T';
  int x,y; cin>>x>>y;
  vector<int> v[2];
  
  int tt=0, nw=0; bool fs=true;
  for(char ch : s) {
    if (ch == 'F') nw++;
    else if (fs) {
      x -= nw; nw=0; tt^=1; fs=false;
    } else {
      if (nw > 0) v[tt].push_back(nw);
      nw=0; tt^=1;
    }
  }/*
  for(int z:v[0]) {
    cout<<z<<" ";
  } cout<<endl;
  for(int z:v[1]) {
    cout<<z<<" ";
  } cout<<endl;*/

  set<int> val[2];

  int n0 = v[0].size(), n1 = v[1].size();
  val[0].insert(0);
  for(int i=0;i<n0;i++) {
    int now = i%2, nex = (i+1)%2;
    val[nex].clear();

    for(int z:val[now]) {
      val[nex].insert(z+v[0][i]);
      val[nex].insert(z-v[0][i]);
    }
    /*
    for(int z:val[nex]) {
      cout<<z<<" ";
    } cout<<endl;*/
  }
  if (val[n0%2].find(x) == val[n0%2].end()) {
    cout<<"No"<<endl;
    return 0;
  }

  val[0].clear(); val[1].clear();
  val[0].insert(0);
  for(int i=0;i<n1;i++) {
    int now = i%2, nex = (i+1)%2;
    val[nex].clear();

    for(int z:val[now]) {
      val[nex].insert(z+v[1][i]);
      val[nex].insert(z-v[1][i]);
    }/*
    for(int z:val[nex]) {
      cout<<z<<" ";
    } cout<<endl;*/
  }
  if (val[n1%2].find(y) == val[n1%2].end()) {
    cout<<"No"<<endl;
    return 0;
  }

  cout<<"Yes"<<endl;
}