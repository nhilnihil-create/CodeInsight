#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;cin>>N;
  if(N%2==0){
    cout<<N*N/4<<endl;
  }
  else{
    cout<<N/2*(N+1)/2<<endl;
  }
}
