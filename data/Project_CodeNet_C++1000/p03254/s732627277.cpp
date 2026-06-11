#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,x;
  cin>>N>>x;
  vector<int> a(N);
  for(int &i:a)
    cin>>i;
  sort(a.begin(),a.end());
  int i=0;
  for(;i<N;i++){
    x-=a[i];
    if(x==0)
      i++;
    if(x<=0)
      break;
    if(i==N-1)
      i++;
  }
  if(i==N+1)
    cout<<N-1;
  else
    cout<<i<<endl;
}