#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  multiset<int> A;
  for (int i=0; i<N; i++){
    int x;
    cin>>x;
    A.insert(x);
  }
  cout<<*A.rbegin()-*A.begin()<<endl;
}