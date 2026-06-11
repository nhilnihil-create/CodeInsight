#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  int ac=(N-M)*100,tle=M*1900;
  cout  << (ac+tle)*pow(2,M) << endl;
  return 0;
}