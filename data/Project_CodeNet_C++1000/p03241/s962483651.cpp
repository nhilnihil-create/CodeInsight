#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,M;cin>>N>>M;
  vector<int> d(0);
  for(int p=1;p*p<=M;p++){
    if(M%p==0){
      d.push_back(p);
      d.push_back(M/p);
    }
  }
  int m=1;
  for(int i=0;i<d.size();i++){
    if(M/d[i]>=N)m=max(m,d[i]);
  }
  cout<<m<<endl;
}
