#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,i;
  cin >> n;
  vector<int> vec(n);
  int p=1;
  for(i=0;i<n;i++){
    cin >> vec.at(i);
    p*=3;
  }
  int ans=1;
  for(i=0;i<n;i++){
    if(vec.at(i)%2==0){
      ans=ans*2;
    }
  }
  cout << p-ans;
}