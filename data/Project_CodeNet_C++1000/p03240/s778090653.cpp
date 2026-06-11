#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Z;
  cin>>N;
  vector<tuple<int,int,int>> p(N);
  for(int i=0;i<N;i++){
    int a,b,c;
    cin>>a>>b>>c;
    p.at(i)=make_tuple(c,a,b);
  }
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  for(int i=0;i<=100;i++){
    for(int j=0;j<=100;j++){
      int h,a,b;
      Z=0;
      tie(h,a,b)=p.at(0);
      int H=h+abs(a-i)+abs(b-j);
      for(int k=1;k<N;k++){
        tie(h,a,b)=p.at(k);
        if(h!=max(H-abs(a-i)-abs(b-j),0)){
          Z++;
          break;
        }
      }
      if(Z==0){
        cout<<i<<" "<<j<<" "<<H<<endl;
        Z=-1;
      }
    }
    if(Z==-1){
      break;
    }
  }
      
}


