#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  int to=n;
  int bl=0;
  int wh=0;
  vector<int>w(n+1);
  vector<int>b(n+1);
  vector<char>x(n);
  rep(i,n){
    cin>>x.at(i);
  }
  rep(i,n){
    if(x.at(i)=='#'){
      bl++;
    }
    w.at(i+1)=bl;
  }
  for (int i = n-1; i >=0; i--){
    if(x.at(i)=='.'){
      wh++;
    }
    b.at(i)=wh;
  }
  rep(i,n){
    to=min(to,w.at(i)+b.at(i+1));
  }  
  cout<<to<<endl;  
}