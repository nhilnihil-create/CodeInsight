#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define ll long long
#define ld long double
//ソートのbegin,end省略
#define all(n) begin(n),end(n)
int main(){
  ll n; cin >> n;
  vector<tuple<string,ll,ll>> p;
  rep(i,n){
    string s; ll nt;
    cin >> s >> nt;
    p.emplace_back(s,-nt,i+1);
  }
  
  sort(all(p));
  
  for(auto v : p){
    cout << get<2>(v) << endl;
  }
}