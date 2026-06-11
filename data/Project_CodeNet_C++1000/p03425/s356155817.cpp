#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

int main(){
  ll n; cin >> n;
  vector<ll> name(5,0);

  rep(i,n){
    string s; cin >> s;
    switch(s.at(0)){
      case 'M':
        name.at(0)++;
        break;
      case 'A':
        name.at(1)++;
        break;
      case 'R':
        name.at(2)++;
        break;
      case 'C':
        name.at(3)++;
        break;
      case 'H':
        name.at(4)++;
        break;
    }
  }

  ll ans = 0;
  for(int i=0;i<3;i++){
    for(int j=i+1;j<4;j++){
      for(int k=j+1;k<5;k++){
        ans += name.at(i)*name.at(j)*name.at(k);
      }
    }
  }

  cout << ans << endl;

}
