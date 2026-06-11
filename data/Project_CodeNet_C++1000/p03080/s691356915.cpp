#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,r=0;
  cin >> n;
  for(int i=0;i<n;i++){
    char in;
    cin >> in;
    if(in=='R')r++;
  }
  if(r>(n-r))cout<<"Yes"<<endl;
  else cout << "No"<<endl;
  return 0;
}