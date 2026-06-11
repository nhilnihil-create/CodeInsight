#include <bits/stdc++.h>
using namespace std;

int main(){

 int N;
 cin >> N;
  
 vector<string> col(N);
 
 for(int i = 0; i < N; i++){
  cin >> col.at(i);
   
  if(col.at(i) == "Y"){
   cout << "Four" << endl;
   break;
  }
   
  else if(i < N - 1){
   continue;
  }
   
  if(col.at(N - 1) != "Y"){
  cout << "Three" << endl;
  }
 }
 
}