#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N;
  cin>>N;
  vector<vector<int64_t>> A(N,vector<int64_t>(3));
  vector<int64_t> ve=A.at(0);
  for(int i=0;i<N;i++){
    cin>>A.at(i).at(0)>>A.at(i).at(1)>>A.at(i).at(2);
    if(A.at(i).at(2)!=0)
      ve=A.at(i);
  }
  int64_t x,y,h;
  for(int64_t i=0;i<=100;i++)
    for(int64_t j=0;j<=100;j++){
      int64_t H=ve.at(2)+abs(ve.at(0)-i)+abs(ve.at(1)-j);
      bool bo=false;
      for(vector<int64_t> &k:A)
        if(k.at(2)!=max(H-abs(k.at(0)-i)-abs(k.at(1)-j),(int64_t)0))
          bo=true;
      if(bo)
        continue;
      x=i;
      y=j;
      h=H;
      break;
    }
  cout<<x<<' '<<y<<' '<<h<<endl;
}