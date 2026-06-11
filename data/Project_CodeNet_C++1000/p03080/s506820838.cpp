#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,r,b;
  string s;
  cin >> n >> s;
  r=0;
  b=0;
  for(i=0;i<n;i++){
    if(s.at(i)=='R'){
      r++;
    }else{
      b++;
    }
  }
  
  if(r>b){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}