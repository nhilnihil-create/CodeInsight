#include<bits/stdc++.h>

#define ll long long
const int inf = 1e9+7;
const ll INF = 1e18+7;

using namespace std;

string s,t;
void rotate(){
  char tmp = s[0];
  s = s.substr(1,s.size()-1);
  s += tmp;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >>s>>t;
  int n = s.size();
  for(int i = 0; i < n;++i){
    if(s == t){
      cout<<"Yes\n";
      return 0;
    }
    rotate();
  }
  cout<<"No\n";
  
}
