#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N;
  string S;
  cin >> N >> S;
  map<pair<string, string>, long long> mp;
  for(int tmp = 0; tmp < 1 << N; tmp++){  
    string sr, sb;//string red, string blue
    for(int i = 0; i < N; i++){  
      if(1 & tmp >> i){  
        sr += S[i]; 
      } else{  
        sb += S[i]; 
      }
    } 
    mp[make_pair(sr, sb)]++;
  }
  long long ans = 0;
  for(int tmp = 0; tmp < 1 << N; tmp++){  
    string sr, sb;//string red, string blue
    for(int i = N-1; i >= 0; i--){  
      if(1 & tmp >> i){  
        sr += S[N + i]; 
      } else{  
        sb += S[N + i]; 
      }
    } 
    ans += mp[make_pair(sr, sb)];
  }
  cout << ans <<endl;
}
