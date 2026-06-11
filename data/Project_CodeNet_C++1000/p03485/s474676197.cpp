#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int N=(a+b)/2;
  if ((a+b)%2==1){
    N++;
  }
  cout<<N<<endl;
}
