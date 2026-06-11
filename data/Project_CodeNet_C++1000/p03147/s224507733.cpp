#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;

int
main() 
{
  int n; cin >> n;
  vector<int> arr(n);
  rep(i, 0, n)cin >> arr[i];

  int interbal = 0;
  while(true){
    rep(index, 0, n){
      if(arr[index] == 0) continue;
      else {
        interbal++;
        while(index < n && arr[index] > 0){
          arr[index]--;
          index++;
        }
      }
    }
    if(*max_element(arr.begin(), arr.end()) == 0) break;
  }
  cout << interbal << endl;

}

