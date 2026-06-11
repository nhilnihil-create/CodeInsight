#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int s=0;
  int x=n;
  while(x>0){
    s+=x%10;
    x/=10;
  }
  cout<<(n%s==0?"Yes":"No")<<endl;
}