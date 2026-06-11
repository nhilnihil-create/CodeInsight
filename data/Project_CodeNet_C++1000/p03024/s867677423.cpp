#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  string s;
  cin >> s;
  int n=s.size(),i,w=0;
  for(i=0;i<n;i++){
    if(s.at(i)=='o'){
      w++;
    }
  }
  
  w += 15-n;
  if(w>=8){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}