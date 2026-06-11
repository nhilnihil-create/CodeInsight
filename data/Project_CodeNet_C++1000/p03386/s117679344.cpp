#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int a,b,k;
  cin>>a>>b>>k;
  long long int t=b-a+1;
  long long int x=min(t,k);
  set<long long int> s;
  for(long long int i=0;i<x;i++){
    s.insert(a);
    a++;
  }
  for(long long int i=0;i<x;i++){
    s.insert(b);
    b--;
  }
  auto itr = s.begin();
   while (itr != s.end()) {
       cout << (*itr) << endl;
       itr++;
   }

}
