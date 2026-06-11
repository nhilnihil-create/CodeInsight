#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N;
  vector<string> SN(N);
  for (int i=0; i<N; i++){
    cin >> SN.at(i);
  }
  cin >> M;
  vector<string> SM(M);
  for (int i=0; i<M; i++){
    cin >> SM.at(i);
  }
  int Amax=0;
  int Achk=0;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if( SN.at(i)==SN.at(j) ){
        Achk++;
        //cout << SN.at(j) << Achk << endl;
      }
    }
    for(int j=0; j<M; j++){
      if( SN.at(i)==SM.at(j) ){
        Achk--;
      }
    }
    if(Amax<Achk) Amax=Achk;
    Achk=0;
  }
  cout << Amax << endl;
  return 0;
}
