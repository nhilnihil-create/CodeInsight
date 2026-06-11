#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  multiset<int> p;
  for (int i=0; i<N; i++){
    int x;
    cin>>x;
    p.insert(x);
  }
  int ex=*p.rbegin();
  ex/=2;
  p.erase(find(p.begin(),p.end(),*p.rbegin()));
  int other_sum=accumulate(p.begin(),p.end(),0);
  cout<<ex+other_sum<<endl;
  
}
  