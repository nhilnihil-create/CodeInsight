#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  string s;
  cin >> s;
  bool is = true;
  if(s[0] != 'A')is = false;
  int cnt_ = 0;
  for(int i = 2;i < s.size()-1;i++)if(s[i] == 'C')cnt_++;
  if(cnt_ != 1)is = false;
  int cnt = 0;
  rep(i,s.size())if(s[i] < 'a')cnt++;
  if(cnt > 2)is =false;
  is ? cout << "AC" << endl : cout << "WA" << endl;




  

  return 0;
}
