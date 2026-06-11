#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a(3);
  cin>> a[0]>>a[1]>>a[2];
  sort(a.begin(),a.end());
  if(a[0]!=a[1]){
    cout << a[0]<< "\n";
  }else{
    cout << a[2] << "\n";
  }
}