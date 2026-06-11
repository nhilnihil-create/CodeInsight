#include<bits/stdc++.h>
using namespace std;
int main(){
  char s,t;
  cin >> s >> t;
  if(s>t){
    cout << ">";
  }else if(s==t){
    cout << "=";
  }else{
    cout << "<";
  }
}
