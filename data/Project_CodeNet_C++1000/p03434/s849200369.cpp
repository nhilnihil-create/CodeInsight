#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector <int> a(n);
  for (int i=0;i<n;i++) cin>>a.at(i);
  //昇順はsort(a.begin(),a.end()),降順はsort(a.rbegin(),a.rend())
  sort(a.rbegin(),a.rend());
  int A=0,B=0;
  for (int i=0;i<n;i++){
    if(i%2==0) A+=a.at(i);
    else B+=a.at(i);
  }
  
  cout<<A-B<<endl;  
}