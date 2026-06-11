#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a.at(i);
  
  sort(a.begin(),a.end());
  
  int k=0;
  
  for(int i=0;i<n;i++){
    if(a.at(i)<=x){
      if(i!=n-1){
        x-=a.at(i);
        k++;
      }
      else if(a.at(i)==x)k++;
    }
    else
      break;
  }
  
  cout << k << endl;
}