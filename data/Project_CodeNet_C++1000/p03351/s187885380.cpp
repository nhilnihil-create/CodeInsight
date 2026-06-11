#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if((max(a,c)-min(a,c))<=d){
    cout << "Yes" << endl;
  }
  else if((max(a,b)-min(a,b))<=d&&(max(c,b)-min(c,b))<=d){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}