#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;
typedef pair<int,int> P;

const ll mod=1000000007;

int ketatume(int a){
  if(a<10)cout<<"00000"<<a;
  else if(a<100)cout<<"0000"<<a;
  else if(a<1000)cout<<"000"<<a;
  else if(a<10000)cout<<"00"<<a;
  else if(a<100000)cout<<"0"<<a;
  else if(a<1000000)cout<<a;
}

int main() {
  int n,m;
  cin >> n >> m;
  P a[m+1];
  vector<vector<P>> p(n+1);
  r(i,m){
    int a,b;
    cin >> a >> b;
    p[a].push_back(P(b,i+1));
  }
  r(i,n){
    if(p[i+1].empty()) continue;
    sort(p[i+1].begin(),p[i+1].end());
    vector<P> v=p[i+1];
    int s=1;
    for(auto && e:v){
      a[e.second]=P(i+1,s);
      s++;
    }
  }
  r(i,m){
    ketatume(a[i+1].first);
    ketatume(a[i+1].second);
      cout<<endl;
  }
}