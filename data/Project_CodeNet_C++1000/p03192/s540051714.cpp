// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll cnt =0;
  string s;
  cin >> s;
  for(auto c:s){
    if(c=='2'){
      cnt++;
    }
  }
  cout << cnt << endl;
}
