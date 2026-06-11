#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,K;
  cin>>A>>B>>K;
  set<int> C;
  for(int i=A;i<A+K&&i<=B;i++)
    C.insert(i);
  for(int i=B;i>B-K&&i>=A;i--)
    C.insert(i);
  for(int i:C)
    cout<<i<<endl;
}