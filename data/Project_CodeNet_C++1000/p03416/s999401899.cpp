#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin>>A>>B;
  int count=0;
  for(A;A<=B;A++){
    if(A/10000==A%10 && A%10000/1000==A%100/10) count++;
  }
  cout<<count<<endl;
}
