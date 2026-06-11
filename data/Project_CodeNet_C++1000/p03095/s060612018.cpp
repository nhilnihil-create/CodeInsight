#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main(){
  long long LARGE = pow(10,9)+7;
  long long N; cin >> N;
  string s; cin >> s;
  map<char,long long> mp_count;
  for(char i='a';i<'z'+1;i++){
    mp_count[i] = 0;
  }
  REP(i,N){
    mp_count[ s[i] ]++;
  }
  long long r = 1;
  for(char i='a';i<'z'+1;i++){
    r *= (mp_count[i]+1);
    r %= LARGE;
  }
  r--;
  cout << r << "\n";
}