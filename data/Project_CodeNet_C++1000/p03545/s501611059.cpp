#include <bits/stdc++.h>
using namespace std;

int main(){
  int s;
  cin >> s;
  vector<int> v;
  for(int i=0; i<4; i++){
    int a=s/pow(10,3-i);
    a%=10;
    v.push_back(a);
  }
  for (int i=0 ; i<(1<<(3)); i++){
    bitset<3> p(i);
    int ans=v[0];
    for (int j=0; j<3; j++){
      if(p[j]==1){
        ans += v[j+1];
      }
      else{
        ans -= v[j+1];
      }
    }
    if (ans==7){
      cout << v[0];
      for(int i=0; i<3; i++){
        if(p[i]==1) cout << "+";
        else cout << "-" ;
        cout << v[i+1];
      }
      cout << "=7";
      break;
    }
  }
}