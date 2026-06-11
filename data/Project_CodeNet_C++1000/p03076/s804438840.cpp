#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(5);
  vector<int> b(5);
  vector<int> c(5);
  for (int i=0;i<5;i++){
  cin >> a.at(i);
  b.at(i)=a.at(i)%10;
  if (b.at(i)==0){
  b.at(i)=10;
  }
  c.at(i)=a.at(i)/10;
  }
  
  sort(b.begin(),b.end());
  for (int i=1;i<5;i++){
  if (b.at(i)==10){
  b.at(i)=0;
  }
  else if(b.at(i)!=10){
  b.at(i)=10;
  }
  }
  if(b.at(0)==10){
  b.at(0)=0;
  }
  cout << b.at(0)+b.at(1)+b.at(2)+b.at(3)+b.at(4)+(c.at(0)+c.at(1)+c.at(2)+c.at(3)+c.at(4))*10 << endl; 
  
}