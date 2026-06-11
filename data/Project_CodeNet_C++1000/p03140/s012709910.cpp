#include<bits/stdc++.h>
using namespace std;

int main(){
 int N;
 cin >> N;
 string a,b,c;
 cin >> a >> b >> c;
 int counter = 0;
 
 for(int i = 0;i < N; i++){
  if(a.at(i) == b.at(i)){
   if(a.at(i) != c.at(i)) counter++;
  }
  else{
   if(a.at(i) == c.at(i) || b.at(i) == c.at(i)) counter++;
   else counter+=2;
   }
  }
  
  cout << counter << endl;
  }