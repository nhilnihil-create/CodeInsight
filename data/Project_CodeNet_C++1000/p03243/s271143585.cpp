#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  for(int i=111; i<1000; i+=111){
    if(N<=i){
      cout << i << endl;
      break;
    }
  }
}
