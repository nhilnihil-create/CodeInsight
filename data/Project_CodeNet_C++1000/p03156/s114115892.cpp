#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  cin >>n>>a>>b;
  int p,j,k,l;
  j=0;
  k=0;
  l=0;
  
  for(int i=0;i<n;i++){
    cin>>p;
    if(p<=a){
      j++;
    }
    else if(p<=b){
      k++;
    }
    else{
      l++;
    }
  }
  
  cout<<min(min(j,k),l)<<endl;
}