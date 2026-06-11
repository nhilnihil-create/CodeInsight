#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> C(N), S(N), F(N);
  for(int i=0; i<N; i++){
    cin >> C.at(i) >> S.at(i) >> F.at(i);
  }
  for(int i=0; i<N-1; i++){
    int Ans=0;
    for(int j=i; j<N-1; j++){
      int mod=Ans%F.at(j);
      if(mod==0){
        mod=F.at(j);
      }
      Ans=max(S.at(j), Ans+F.at(j)-mod);
      Ans+=C.at(j);
    }
    cout << Ans << endl;
  }
  cout << 0 << endl;
}