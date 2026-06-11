#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  int odd = n%2;
  if(odd)n--;

  vector<pair<ll, ll>> g;
  if((odd+n)>=5)rep(i, n/2-1){
    g.push_back(make_pair(i+1, i+2));
    g.push_back(make_pair(i+1, n-1-i));

    g.push_back(make_pair(n-i, i+2));
    g.push_back(make_pair(n-i, n-1-i));
  }

  if(odd){
   n++;
    g.push_back(make_pair(1, n));
    g.push_back(make_pair(n-1, n));
    if(n>3){
      g.push_back(make_pair(n, (n-1)/2));
      g.push_back(make_pair(n, (n-1)/2+1));
    }
  }else{
    g.push_back(make_pair(1, n/2));
    g.push_back(make_pair(1, n/2+1));
    g.push_back(make_pair(n, n/2));
    g.push_back(make_pair(n, n/2+1));
  }
  cout<<g.size()<<endl;
  rep(i, g.size())cout<<g[i].first<<' '<<g[i].second<<endl;

  return 0;
}