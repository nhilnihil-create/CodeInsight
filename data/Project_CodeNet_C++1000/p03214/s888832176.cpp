#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,j=0;
  cin>>N;
  vector<int> a(N);
  for(int &i:a){
    cin>>i;
    j+=i;
  }
  double h=(double)j/N,k=10000;
  int l=-1;
  for(int i=0;i<N;i++){
    if(abs(a[i]-h)<k){
      k=abs(a[i]-h);
      l=i;
    }
  }
  cout<<l<<endl;
}