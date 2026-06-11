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

bool small(char cc){
  return ((cc - 'a') >= 0) && ((cc - 'a') < 26);
}

int main(){
  string S;
  cin >> S;

  if(S[0] != 'A'){
    cout << "WA" << endl;
    return 0;
  }
  if(!small(S[1]) || !small(S[S.size() - 1])){
    cout << "WA" << endl;
    return 0;
  }

  ll cnt = 0;
  rep2(i, 2, S.size() - 1){
    if(!small(S[i])){
      if(S[i] == 'C'){
		cnt++;
      } else{
        cout << "WA" << endl;
        return 0;
      }
    }
  }

  if(cnt != 1){
    cout << "WA" << endl;
    return 0;
  }

  cout << "AC" << endl;
  
  return 0;
}
