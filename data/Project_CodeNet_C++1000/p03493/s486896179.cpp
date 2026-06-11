#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

int main(){
  string a;
  cin >> a;
  
  int count = 0;
  rep(i,3){
    if(a[i] == '1') count++;
  }
  
  cout << count << endl;
  
  return 0;
}
