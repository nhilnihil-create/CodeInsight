#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  
  int a[n];
  for(int i = 0;i < n; ++i){
    cin >> a[i];
  }
  
  sort(a,a+n);
  
  int c = 0;
  for(int i = 0; i < n-1; ++i){
    c += a[i];
  }
  
  if(c > a[n-1]){
    cout << "Yes";
  }else{
    cout << "No";
  }
}