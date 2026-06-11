#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;

int 
main()
{
  string S; cin >> S;
  int K; cin >> K;
  int num = S.size() * (S.size() + 1) / 2;
  set<string> substring;
  rep(i, 0, S.size()){
    rep(k, 1, 5.6){
      substring.insert(S.substr(i, k));
    }
  }

  vector<string> arr;
  for(auto s: substring){
    arr.push_back(s);
  }

  sort(arr.begin(), arr.end());

  cout << arr[K -1] << endl;

}
