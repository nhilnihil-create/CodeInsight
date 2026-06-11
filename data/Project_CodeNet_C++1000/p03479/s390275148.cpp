#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,l;
  cin>>n>>l;
  int num=0;
  while(n<=l){
    n*=2;
    num++;
  }
  cout<<num<<endl;
}
 
