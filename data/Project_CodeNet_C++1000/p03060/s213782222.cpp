#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    p[i]-=a;
  }
  int A=0;
  for(int i=0;i<N;i++){
    if(p[i]>0){
      A+=p[i];
    }
  }
  cout<<A<<endl;
}