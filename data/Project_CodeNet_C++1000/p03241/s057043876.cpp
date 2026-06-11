#include <bits/stdc++.h>
using namespace std;


int main() {

long N,M;
cin>>N>>M;
vector<int> d;

for(int i=1;i*i<=M;i++){
  if(M%i==0){
    d.push_back(i);
    if(i*i!=M) d.push_back(M/i);
  }
}

sort(d.begin(),d.end());


for(int i=0;i<d.size();i++){
  if(d[i]>=N){
    cout<<M/d[i]<<endl;
    return 0;
  }
}

}
