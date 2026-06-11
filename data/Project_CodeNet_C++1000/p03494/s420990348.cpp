#include <bits/stdc++.h>
using namespace std;
long long func(long long x){
long long count=0;
  while(x%2!=1){
    count++;
  x/=2; 
  }
  return count;
}
int main(){
int N;
  cin>>N;
  vector<long long> a(N);
  for(int i=0;i<N;i++)
    cin>>a.at(i);
  long long min=func(a.at(0));
  for(int i=0;i<N;i++){
    if(min>func(a.at(i)))
      min=func(a.at(i));
  }
  cout<<min<<endl;
}