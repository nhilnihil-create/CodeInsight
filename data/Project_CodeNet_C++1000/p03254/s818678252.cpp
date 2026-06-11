#include <bits/stdc++.h>
using namespace std;

int main(){

  int n,x;
  cin>>n>>x;
   vector<int> vec(n);
  for(int i=0;i<n;i++){
    cin >>vec.at(i);}

  sort(vec.begin(), vec.end());
  int count=0;
  for(int i=0;i<n;i++){
    if(i==n-1 && vec[n-1] < x)break;
    if(vec[i] <=x ){
  count++;
    x = x-vec[i];
    
  
  }else
  {
   
    break;}
  }
   cout<< count <<endl;
}
