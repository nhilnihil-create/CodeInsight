#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >>N;

  int count=10000000;

  for(int i=0; i<N; i++){
    int x;
    cin>>x;
    int z=0;
    while(x%2==0){
      x/=2;
      z++;
    }
    if(count>z)
    count=z;

  }

  cout <<count<<endl;

}
