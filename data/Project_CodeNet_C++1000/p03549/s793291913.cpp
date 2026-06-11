#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,M;
  cin>>N>>M;
  
  int kaz=pow(2,M);
  cout<<(M*1900+100*(N-M))*kaz<<endl;
  
}
