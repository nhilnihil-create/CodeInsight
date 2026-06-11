#include <bits/stdc++.h>
using namespace std;



int main(){
  int64_t N;
  cin>>N;
  
  vector<int64_t> vec(N);
  vector<int64_t> moto(N);
  for(int i=0;i<N;i++){
    int64_t m;
    cin>>m;
    vec.at(i)=m;
    moto.at(i)=m;
  }
  sort(vec.begin(),vec.end());
  int64_t a=vec.at(N/2-1);
  int64_t b=vec.at(N/2);
  for(int i=0;i<N;i++){
    int64_t p=moto.at(i);
    if(p<=a) cout<<b<<endl;
    else if(p>=b) cout<<a<<endl;
    
  }

}