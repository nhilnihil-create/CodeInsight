#include<iostream>
using namespace std;

int main(){
  long long a,b,c,k;cin>>a>>b>>c>>k;
  cout<<(k&1?b-a:a-b)<<endl;
  return 0;
}