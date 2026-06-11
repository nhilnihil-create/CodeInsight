#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main(){
  int a,c,b;cin >> a >> c >> b;
  if(a>c){
    if(a>=b&&b>=c)cout << "Yes";
    else cout << "No";
  } else {
    if(a<=b&&b<=c)cout << "Yes";
    else cout << "No";
  }
}

