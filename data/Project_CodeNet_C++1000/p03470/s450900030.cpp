#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;


int main() {
  int n,w,count=0;
  cin >>n;
  set<int> s;
  rep(i,n){
    cin >>w;s.insert(w);
  }
  for(auto au:s){
    count++;
  }
  cout<< count<<endl;
}