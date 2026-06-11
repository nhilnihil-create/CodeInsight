#include <bits/stdc++.h>
using namespace std;

#define INF 100000000000000

int main() {


  int64_t n;
  cin>>n;

  vector<int64_t> ope(n+1,INF);
  ope.at(0)=0;
  ope.at(1)=1;
  for(int i=2;i<=n;i++){
    int64_t ope1=INF,ope6=INF,ope9=INF;

    ope1 = ope.at(i-1)+1;

    int64_t wk=1;
    while(i-pow(6,wk)>=0){
      ope6 = min(ope6, ope.at(i-pow(6,wk))+1);
      wk++;
    }
      
    wk=1;
    while(i-pow(9,wk)>=0){
      ope9 = min(ope9, ope.at(i-pow(9,wk))+1);
      wk++;
    }  

    ope.at(i)=min(ope1,min(ope6,ope9));
  }

  cout<<ope.at(n)<<endl;

  return 0;
}
