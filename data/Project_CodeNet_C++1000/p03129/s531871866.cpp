#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a>>b;
  if (a%2!=0){
    a++;
  }
  if (a/b>=2){
    cout <<"YES"<<endl;
  }
  else{
    cout <<"NO"<<endl;
  }
}