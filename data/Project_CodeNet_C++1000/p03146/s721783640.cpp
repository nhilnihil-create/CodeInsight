#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int  main(){
  int n; cin>>n;
  set<int> s;
  s.insert(n);
  int c=2;
  while (true){
    if(n%2==0){n/=2;}
    else{n=n*3+1;}
    if(s.count(n)){cout<<c;break;}
    else{s.insert(n);c++;}
  }
  
}