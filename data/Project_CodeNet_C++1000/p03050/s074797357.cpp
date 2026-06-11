#include <bits/stdc++.h>
using namespace std;

vector<int64_t> divisor(int64_t n){
  vector<int64_t> div;
  for(int64_t i=1;i*i<= n;++i) {
    if(n%i==0) {
      div.push_back(i);
      if(i*i!=n) div.push_back(n/i);
    }
  }
  sort(begin(div),end(div));
  return (div);
}

int main(){
  int64_t N;
  cin>>N;
  vector<int64_t> d;
  d=divisor(N);
  int64_t sum=0;

  for(int i=0;i<d.size();++i){
    int64_t m=(N/d[i])-1;
    if(d[i]<m){
      sum +=m;
    }
  }
  cout<<sum<<endl;
}
