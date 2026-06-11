#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,k,c=0;
  cin>>N;
  vector<int> d(N);
  
  for(int i=0;i<N;i++){
    cin>>d.at(i);
    k=0;
    for(int j=0;j<i;j++){
      if(d.at(j)==d.at(i))k++;
    }
    if(k==0)c++;
  }
  cout<<c<<endl;
}