#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,k;
  vector<int> map;
  cin >> a >> b >> k;
  for(int i=min(a,b); i>0; --i){
    if(a >=i && b >= i && a%i == 0 && b%i ==0){
      map.push_back(i);
    }
  }
  cout << map[k-1] << endl;
}
