#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C, X,Y;
  cin>>A>>B>>C>>X>>Y;
  vector<int>a(100001);
  for(int i=0;i<=100000;i++){
    a.at(i)=2*i*C+A*max(0,X-i)+B*max(0,Y-i);
  }
  sort(a.begin(),a.end());
  cout<<a.at(0)<< endl;
}