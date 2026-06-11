#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;  cin >> N;
  int Q;  cin >> Q;
  string S; cin >> S;
  vector<int>AC(N+1,0);
  for(int i=1;i<N;i++){
    if(S.at(i-1) == 'A' && S.at(i) == 'C'){
      for(int j=i+1;j<=N;j++){
        AC.at(j)++;
      }
    }
  }
  for(int i=0;i<Q;i++){
    int l,r;  cin >> l >> r;
    cout << AC.at(r) - AC.at(l) << endl;
  }
}