#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,h,n,w; cin>>N;
  bool finish=false;
  for(int i=1; i<=3500; i++){
    for(int j=1; j<=3500; j++){
      if(4*i*j-N*(i+j)==0) continue;
      if(N*i*j%(4*i*j-N*(i+j))==0){
        w=N*i*j/(4*i*j-N*(i+j));
        if(w<=0) continue;
        h=i, n=j;
        finish=true;
        break;
      }
    }
    if(finish) break;
  }
  cout<<h<<" "<<n<<" "<<w<<endl;
}