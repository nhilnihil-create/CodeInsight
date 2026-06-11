#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n;cin>>n;
  vector<int> d(n), d1, d2;
  map<int, int> m;
  rep(i, n){
    cin>>d[i];
    m[ d[i] ]++;
  }

  if(n==1) { cout << d[0] << endl; return 0; }

  for(auto p:m)if(p.second>2) { cout<< 0 <<endl; return 0; }

  for(auto p:m){
    if(p.second==2){
      d2.push_back( p.first );
      d2.push_back( 24-p.first );
    }else{
      d1.push_back(p.first);
    }
  }

  int result=0;
  rep( s, 1<<d1.size() ){
    int c = 0;
    vector<int> times({0, 24});
    rep(i, d1.size()){
      if(s & 1<<i)times.push_back( 24-d1[i] );
      else times.push_back( d1[i] );
    }

    for(auto p:d2)times.push_back(p);

    int t = 24;
    sort(times.begin(), times.end());
    rep(i, times.size()-1) t = min(t, times[i+1] - times[i] );
    result = max(result, t);
  }

  cout<<result<<endl;

  return 0;
}
