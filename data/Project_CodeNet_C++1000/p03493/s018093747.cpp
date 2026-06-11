

    
  
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
  string s;
  int cnt =0;
  cin >> s;
  rep(i,s.size()){
    if(s.at(i)=='1') cnt++;
  }
  
  cout << cnt << endl;
  
}
    