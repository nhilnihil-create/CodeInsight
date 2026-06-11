#include <bits/stdc++.h>
using namespace std;

int K=0;
vector<int> t;
vector<int> b;
vector<int> d;
void PB(int A,int B,int C){
  t.push_back(A);
  b.push_back(B);
  d.push_back(C);
  K++;
}

int main() {
  int L;
  cin>>L;
  int Q=1;
  while(L>0){
    int Y=L%3;
    for(int j=0;j<Y;j++){
      L--;
      PB(Q,20,L);
    }
    if(L<=0){
      Q++;
      break;
    }
    L/=3;
    PB(Q,Q+1,0);
    PB(Q,Q+1,L);
    PB(Q,Q+1,L*2);
    Q++;
  }
  while(Q<19){
    PB(Q,Q+1,0);
    Q++;
  }
  cout<<20<<" "<<K<<endl;
  for(int i=0;i<K;i++){
    cout<<t[i]<<" "<<b[i]<<" "<<d[i]<<endl;
  }
}