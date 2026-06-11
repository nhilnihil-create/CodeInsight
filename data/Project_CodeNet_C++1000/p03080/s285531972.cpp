#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, r=0;
  cin >> a;
  string n;
  cin >> n;
  for(int i=0;i<a;i++){
    if(n.at(i)=='R'){
      r+=1;
    }
  }
  if(r>a-r){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
