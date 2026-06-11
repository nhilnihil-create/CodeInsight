#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int64_t MOD=10000007;

int main() {
  int64_t N,M;
  cin>>N>>M;
  for(int64_t i=M;i>0;i--){
    if(i*N<=M&&M%i==0){
    cout<< i;
    break;
    }
  }
}
