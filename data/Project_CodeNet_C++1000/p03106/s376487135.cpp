#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,K;
  cin>>A>>B>>K;
  multiset<int> x;
  for (int i=1; i<=100; i++){
    if ((A%i==0)&&(B%i==0)){
      x.insert(i);
    }
  }
  int k=1;
  while (K>k){
    x.erase(*x.rbegin());
    k++;
  }
  cout<<*x.rbegin()<<endl;
}