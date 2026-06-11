#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  int timer = 100*(n-m)+1900*m;
  int excute = 1;
  while(m--) excute*=2;
  cout<<timer*excute;
}