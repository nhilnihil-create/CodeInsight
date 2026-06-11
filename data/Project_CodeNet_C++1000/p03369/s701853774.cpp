#include <iostream>
using namespace std;

int main(){
  string S;
  cin >> S;
  int count = 700;
  if(S[0]=='o'){
    count+= 100;}
  if(S[1]=='o'){
    count +=100;}
   if(S[2]=='o'){
     count+=100;}
  
  cout << count<<endl;
}
    