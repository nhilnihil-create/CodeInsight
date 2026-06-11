#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

bool compare_by_nested_pair_second(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.second < b.second;
}

int main(){
  int n;cin>>n;
  vector<pair<pair<ll,ll>, ll>> ab(n);
  rep(i,n){
    ll a,b;cin>>a>>b;
    auto p = make_pair(a, b);
    ab[i] = make_pair(p, a+b);
  }

  sort(ab.rbegin(), ab.rend(), compare_by_nested_pair_second);
//  sort(ab.begin(), ab.end(), compare_by_nested_pair_second);

//rep(i,n)cout<<ab[i].second<<' ';cout<<endl;

  ll result=0;
  rep(i,n){
    if(i%2==0) result += ab[i].first.first;
    else result -= ab[i].first.second;
  }

  cout<<result;

  return 0;
}