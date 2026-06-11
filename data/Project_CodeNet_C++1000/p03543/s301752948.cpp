#include <bits/stdc++.h>
using namespace std;
int main() {
int N;
  cin>>N;
  int a=N%1000;
  int b=a%111;
  int c=N/10;
  int d=c%111;
  if(b==0)cout<<"Yes"<<endl;else{if(d==0)cout<<"Yes"<<endl;else cout<<"No"<<endl;}
}