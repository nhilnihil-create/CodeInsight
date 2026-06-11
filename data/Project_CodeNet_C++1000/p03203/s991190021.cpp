#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
#include <map>
#include <unordered_map>
#include <set>
using namespace std; typedef long long ll; const int MINF=-1e9; typedef pair<int,int> P;

int main() {
  int h,w; cin>>h>>w;
  /*
  string ss[h]; for(int i=0;i<h;i++) cin>>ss[i];
  
  int n=0;
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      if (ss[i][j] == '#') n++;
    }
  }

  int x[n], y[n];
  set<P> s;
  for(int i=0,k=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      if (ss[i][j] == '#')
        x[k]=i, y[k]=j, s.insert({i,j}), k++;
    }
  }*/
  
  int n; cin>>n;
  int x[n], y[n];
  set<P> s;
  for(int i=0;i<n;i++) {
    cin>>x[i]>>y[i]; x[i]--; y[i]--;
    s.insert({x[i],y[i]});
  }

  int t[w]; for(int i=0;i<w;i++) t[i]=h;
  {
    int i=0,j=0;
    while(i<h && j<w) {
      //cout<<i<<" "<<j<<endl;
      if (s.find({i,j}) != s.end()) j--;
      //cout<<i<<" "<<j<<endl;
      t[j]=min(i,t[j]); i++; j++;
    }
  }
  //for(int i=0;i<w;i++) cout<<t[i]<<" "; cout<<endl;
  int an=h;
  for(int i=0;i<n;i++) {
    if (t[y[i]] < x[i]) an=min(an, x[i]);
  }
  cout<<an<<endl;
}