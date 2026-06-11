#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(a != b ){
    if(a != c){
      cout << a << endl;
    }else{
      cout << b << endl;
    }
  }else{
    cout << c << endl;
  }
  return 0;
}
