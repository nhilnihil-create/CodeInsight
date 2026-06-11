#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,c=0;
  string s;
  cin >> s;
  n=s.size();
  for(i=0;i<n;i++){
    if(s.at(i)=='0'+i%2){
      c++;
    }
  }
  
  cout << min(c,n-c) << endl;
} 