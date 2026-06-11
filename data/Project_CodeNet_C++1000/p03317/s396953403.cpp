#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  int s=0;
  while(n>k+(k-1)*(s-1)){
    s++;
  }
  cout<<s<<endl;
}
