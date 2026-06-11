#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll n;
  cin >> n;
  vl v(n);
  rep(i, n) cin >> v[i];
  
  map<ll, ll> odd, even;

  for(int i = 0; i < n; i += 2){
    odd[v[i]]++;
    even[v[i + 1]]++;
  }

  priority_queue<pll> odd2, even2;

  for(auto it = odd.begin(); it != odd.end(); it++)
    odd2.push({it->second, it->first});
  for(auto it = even.begin(); it != even.end(); it++)
    even2.push({it->second, it->first});

  if(odd2.size() == 1)
    odd2.push({0, 100001});
  if(even2.size() == 1)
    even2.push({0, 100002});

  if(odd2.top().second == even2.top().second){
    if(odd2.top().first > even2.top().first)
      even2.pop();
    else if(odd2.top().first < even2.top().first)
      odd2.pop();
    else{
      pll odd_top = odd2.top();
      pll evet_top = even2.top();

      odd2.pop();
      even2.pop();

      if(odd2.top().first >= even2.top().first)
		even2.push(odd_top);
      else
		odd2.push(evet_top);
    }
  }
  
  cout << n - odd2.top().first - even2.top().first << "\n";
    
  return 0;
}
