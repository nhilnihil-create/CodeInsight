#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B,C;
  cin>>N>>A>>B>>C;
  vector<int> l(N);
  for(int i=0;i<N;i++){
    cin>>l[i];
  }
  vector<int> p((1<<N),167167167);
  vector<int> q((1<<N),167167167);
  vector<int> r((1<<N),167167167);
  for(int i=1;i<(1<<N);i++){
    int L=0,X=0;
    vector<int> a;
    for(int j=0;j<N;j++){
      if(i&(1<<j)){
        L+=l[j];
      }
      else{
        a.push_back(j);
        X++;
      }
    }
    for(int j=0;j<(1<<X);j++){
      int Y=i;
      for(int k=0;k<X;k++){
        if(j&(1<<k)){
          Y+=(1<<a[k]);
        }
      }
      p[Y]=min(p[Y],abs(L-A)+10*(N-X-1));
    q[Y]=min(q[Y],abs(L-B)+10*(N-X-1));
    r[Y]=min(r[Y],abs(L-C)+10*(N-X-1));
    }
  }
  int Z=167167167;
  for(int i=1;i<(1<<N);i++){
    for(int j=1;j<(1<<N);j++){
      if(i&j){
        continue;
      }
      int k=((1<<N)-1)^(i|j);
      Z=min(Z,p[i]+q[j]+r[k]);
    }
  }
  cout<<Z<<endl;
}