#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  
  for (int i = 0; i < N; i++) {
    char x;
    cin >>x;
    if (x=='Y'){
      cout<<"Four"<<endl;
      break;
    }
    else if(i==N-1){
      cout<<"Three"<<endl;
    }
  }
}