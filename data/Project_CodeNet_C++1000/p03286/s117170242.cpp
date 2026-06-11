#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;
using G = vector<map<int, int>>;

int 
main() {

  int N; cin >> N;
  vector<int> ans;
  int count = 0;
  
  if(N == 0){
    cout << 0 << endl;
    return 0;
  }

  while( N != 0){
    if(N % 2 != 0) ans.push_back(1), N--;
    else ans.push_back(0);
    N /= -2;
    ++count;
  }

  for(int i = count - 1; i >= 0; --i){
    cout << ans[i];
  }
  cout << endl;

}