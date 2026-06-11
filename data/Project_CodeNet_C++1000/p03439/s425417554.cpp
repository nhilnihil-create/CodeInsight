// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll n,le,ri,h,sta;
  string s,t;
  cin >> n;
  cout << 0<<endl;
  cin >> s;
  if(s=="Vacant"){
    return 0;
  }
  le = 1;
  ri = n;
  sta = 0;
  while(true){
    h = (le+ri)/2;
    cout << h << endl;
    cin >> t;
    if(t=="Vacant"){
      break;
    }else if((h%2==1)^(t==s)){
      le = h+1;
    }else{
      ri = h;
    }
  }
}
