#include <bits/stdc++.h>
using namespace std;

int main(){
  double n,m,d;
  cin>>n>>m>>d;
  int a=1;
  if(d>0){
    a++;
  }
  cout<<fixed<<setprecision(15);
  cout<<(m-1)*(a*(n-d))/(n*n)<<endl;
}