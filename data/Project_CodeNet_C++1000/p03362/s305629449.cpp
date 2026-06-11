#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin>>N;
  vector<long> a;
  int idx=0;
  for(int i=31;i<=55555;i+=30){
    bool flg=true;
    for(int j=2;j*j<=i;j++){
      if(i%j==0) flg=false;
    }
    if(flg) a.push_back(i);
  }
  for(int i=0;i<N;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  }
