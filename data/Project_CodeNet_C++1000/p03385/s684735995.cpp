#include<bits/stdc++.h>
using namespace std;
int main(){
  int n=0,m=0,l=0;
  string s;
  cin >> s;
  for(int i=0;i<3;i++){
    if(s.at(i)=='a'){
      n++;
    }
    else if(s.at(i)=='b'){
      m++;
    }
    else if(s.at(i)=='c'){
      l++;
    }
  }
  if(n==1&&m==1&&l==1){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}