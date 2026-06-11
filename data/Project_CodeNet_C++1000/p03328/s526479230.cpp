#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B;
  cin>>A>>B;
  
  int n=B-A-1;
  
  int sum=0;
  
  for(int i=1;i<=n;i++){
    sum+=i;
  }
  
  cout<<sum-A<<endl;
}