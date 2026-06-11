#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
 string s;
  cin>>s;
  int n0=count(s.begin(),s.end(),'0');
  int n1=count(s.begin(),s.end(),'1');
  cout<<min(n0,n1)*2;
}