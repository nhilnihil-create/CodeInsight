#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n,k;cin>>n>>k;
  vector<int> v(n);
  int x=k;
  int c=1;
  while(true){
    if(x>=n){break;}
    x+=k-1;c++;
  }
  
  cout<<c;
}
      

