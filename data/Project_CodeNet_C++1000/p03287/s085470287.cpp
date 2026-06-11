#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  map<int,int> m;
  int64_t Z=0,A=0;
  m[0]=1;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A=(A+a)%M;
    m[A]++;
    Z+=m[A];
  }
  Z-=N;
  cout<<Z<<endl;
}

