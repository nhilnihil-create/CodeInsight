#include <bits/stdc++.h>
int main(){
  int N,M;
  std::cin>>N>>M;
  int m=1<<M;
  std::cout<<100*m*(N+18*M);
}