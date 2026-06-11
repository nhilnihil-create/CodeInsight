#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> L(N);
  for(int i=0; i<N; i++){
    cin >> L.at(i);
  }
  int Ans=10000000;
  int subAns=0;
  for(int i=0; i<(int)pow(4, N); i++){
    int P=i;
    vector<int> result(4);
    vector<int> Num(4);
    subAns=0;
    for(int j=0; j<N; j++){
      result.at(P%4)+=L.at(j);
      Num.at(P%4)++;
      P/=4;
    }
    if(Num.at(0)*Num.at(1)*Num.at(2)!=0){
      subAns=(Num.at(0)+Num.at(1)+Num.at(2)-3)*10+abs(result.at(0)-A)+abs(result.at(1)-B)+abs(result.at(2)-C);
      Ans=min(Ans, subAns);
    }
  }
  cout << Ans << endl;
}