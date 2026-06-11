#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  
  if(N%111==0){
    cout<<N<<endl;
  }
  else{
    while(true){
      N++;
      if(N%111==0){
        cout<<N<<endl;
        break;
      }
    }
  }
}