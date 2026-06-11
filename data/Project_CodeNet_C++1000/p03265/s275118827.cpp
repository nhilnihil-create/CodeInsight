#include<bits/stdc++.h>
using namespace std;

int main(){
  pair<int, int> a, b;
  int p, q,s,t;
  cin>>p>>q;
  a=make_pair(p, q);
  cin>>p>>q;
  b=make_pair(p, q);
  p=a.second-b.second+b.first;
  q=b.first-a.first+b.second;
  cout<< p <<" "<<q<<" ";
  s=a.first-b.first+p;
  t=a.second-b.second+q;
  cout<<s<<" "<<t<<endl;
}