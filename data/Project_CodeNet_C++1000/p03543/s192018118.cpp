#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  
  int X;
  X=N%1000;
  
  if (N%1110<10 || X%111==0 || N%1000==0){
    cout<<"Yes"<<endl;
  }
  else {
    cout<<"No"<<endl;
  }
}