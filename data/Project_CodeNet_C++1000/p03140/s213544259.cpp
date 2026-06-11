#include <bits/stdc++.h>
using namespace std; 
    
int main(){
  int N,count=0;
  string A,B,C;
  cin >> N >> A >> B >> C;
  for(int i=0;i<N;i++){
    if(A.at(i)==B.at(i) && B.at(i)==C.at(i)){
      continue;
    }
    if(A.at(i)!=B.at(i) && B.at(i)!=C.at(i) && C.at(i)!=A.at(i)){
      count+=2;
    }
    else{
      count++;
    }
  }
  cout << count << endl;
}