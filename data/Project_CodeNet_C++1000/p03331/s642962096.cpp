#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int sum(int m){
  return (m/1)%10+(m/10)%10+(m/100)%10+(m/1000)%10+(m/10000)%10;
}

int main() {
  int N,m;
  m=50;
  cin>>N;
  	for(int i=1;i<N;i++){
      m=min(m,sum(i)+sum(N-i));
    }
  cout<<m<<endl;
}