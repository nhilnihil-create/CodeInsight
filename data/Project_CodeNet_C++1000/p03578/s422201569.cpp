#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;
///vector<pair<string, int>>;

int main(){
  int n, m, t;
  cin >> n;
  map<int, int> ca;
  rep(i, n) {
    int x;
    cin >> x;
    ca[x]++;
  }
  cin >> m;
  while(m --){
    cin >> t;
    if(ca[t]){
      ca[t]--;
    } else{
      cout << "NO";
      return 0;
    }
  }
cout <<"YES";
}
