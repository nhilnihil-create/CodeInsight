#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int>a(3);
  cin>>a[0]>>a[1]>>a[2];
  
  int k; cin>>k;
  
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  
  for(int i=0;i<k;i++){
    a[0]*=2;
  }
  
  int sum=0;
  
 for(int i=0;i<3;i++){
   sum+=a[i];
 }
  cout<<sum<<endl;
  
}
