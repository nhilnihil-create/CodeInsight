#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;

int main(){
  string s; cin>>s;
  vector<int>V(4);
  rep(i,4) V[i] = s[i]-'0';
  
  for (int bit=0; bit<(1<<3); bit++){
  	int sum = V[0];
    for (int i=0; i<3; i++){
      if (bit & (1<<i)) sum += V[i+1];
      else sum -= V[i+1];
    }
    if (sum == 7){
      cout << V[0];
      for (int i=0; i<3; i++){
        if (bit & (1<<i)) cout << "+" << V[i+1];
        else cout << "-" << V[i+1];
      }
      cout << "=7" << endl;
      return 0;
    }
  }
}