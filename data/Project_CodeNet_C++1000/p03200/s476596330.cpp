#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

long long int max(long long int a,long long int b){
  if(a>b)
    return a;
  else
    return b;
}
typedef pair<int,int> pii;
typedef vector<int> vec;
void solve(){
  string s;
  cin>>s;
  int n = s.length();
  vec pref(n);
  pref[0] = (s.at(0)=='B'?1:0);
  for(int i = 1;i<n;i++){
    if(s.at(i)=='B'){
      pref[i] = pref[i-1]+1;
    }
    else{
      pref[i] = pref[i-1];
    }
  }

  lli ans = 0;
  for(int i = 0;i<n;i++){
    if(s.at(i)=='W'){
      ans+=pref[i];
    }
  }

  cout<<ans;
}

int main(){
  solve(); 
}