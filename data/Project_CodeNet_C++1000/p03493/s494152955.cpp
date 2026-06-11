#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,a,b,c;
  cin>>N;
  a = N/100;
  b = N/10 - a*10;
  c = N - a*100-b*10;
  cout << a+b+c<<endl;
}