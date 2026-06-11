#include <bits/stdc++.h>
#define ALL(x) (x).begin(),(x).end()
using namespace std;

int main(){
  vector<int> p;
  for(int i=3;i<=1e5;i+=2){
    int n=floor(sqrt(i)),b=1;
    for(int d=2;d<=n;d++){
      int j=(i+1)/2;
      if(i%d==0||j%d==0){
        b=0;
        break;
      }
    }
    if(b) p.push_back(i);
  }

  int Q,l,r; cin>>Q;
  for(int i=0;i<Q;i++){
    cin>>l>>r;
    cout<<upper_bound(ALL(p),r)-lower_bound(ALL(p),l)<<endl;
  }
}