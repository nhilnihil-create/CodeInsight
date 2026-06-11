#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  vector<int> T(3);
  cin >> N >> T[0] >> T[1] >> T[2];
  vector<int> L(N);
  for(int i=0; i<N; i++) cin >> L[i];
  
  vector<int> Ltemp(4);
  int result=1e9;
  for(int i=0; i<(1<<(2*N)); i++){
    int mp=0;
    for(int l=0; l<4; l++){
      Ltemp[l]=0;
    }
    for(int j=0; j<N; j++){
      int a=((i&(1<<(2*j)))>0?1:0);
      int b=((i&(1<<(2*j+1)))>0?1:0);
      if(a*b==0&&Ltemp[a+2*b]>0) mp+=10;
      Ltemp[a+2*b]+=L[j];
    }
    for(int k=0; k<3; k++){
      if(Ltemp[k]==0) mp+=1e8;
      mp+=abs(T[k]-Ltemp[k]);
    }
    result=min(result,mp);
  }
  cout << result << endl;
}