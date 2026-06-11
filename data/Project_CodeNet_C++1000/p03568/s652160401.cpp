#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,S=1,T=1,a;cin>>N;
  for(int i=0;i<N;i++){
    S*=3;cin>>a;
    if(a%2==0)T*=2;
  }
  cout<<S-T<<endl;
}