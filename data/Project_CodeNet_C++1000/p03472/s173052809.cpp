#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,H,A=0,M=0;
  cin>>N>>H;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    int a,b;
    cin>>a>>b;
    p.at(i)=b;
    M=max(M,a);
  }
  sort(p.begin(), p.end());
reverse(p.begin(), p.end());
  int j=0;
  while(p.at(j)>M&&H>0){
    H-=p.at(j);
    A++;
    j++;
    if(j==N){
      break;
    }
  }
  if(H>0){
    A+=1+(H-1)/M;
  }
  cout<<A<<endl;     
}