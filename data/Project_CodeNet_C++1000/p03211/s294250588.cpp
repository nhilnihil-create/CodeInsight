#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;
const int INF=1001001001;

int main() {
  string s;
  cin>>s;
  int a=INF;
  rep(i,s.size()){
    int n=stoi(s.substr(i,3));
    a=min(a,abs(n-753));
  }
  cout<<a<<endl;
    
}
