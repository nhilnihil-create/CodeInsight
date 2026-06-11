#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
#define repi(i,a,b) for (int i=a;i<(b);i++)
using namespace std;
typedef long long ll;

int main(){

  cin.tie(0); //cin高速化
  ios::sync_with_stdio(false); //cin高速化
  
  string s;
  int w;
  cin >> s >> w;
  int n = s.size();
  string a;
  for(int i=0;i<n;i=i+w){
    string str = s.substr(i,w);
    a += str[0];
  }
  cout<<a<<endl;
    
  return 0;
}
    