#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  for(int i=100000;i>=0;i--){
    if((long long)i*i<=N){
      cout<<i*i<<endl;
      return 0;
    }
  }
}