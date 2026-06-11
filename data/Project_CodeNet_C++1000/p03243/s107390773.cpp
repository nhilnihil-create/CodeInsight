#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  cout<<(N%111==0?N:((N+110)/111)*111)<<endl;
}
  
