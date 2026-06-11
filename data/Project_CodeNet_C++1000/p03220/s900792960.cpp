#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, A;
  cin >> N >> T >> A;
  
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin >> H.at(i);
  }
  
  int gosa = 100000000;
  int chiten = 0;
  
  for(int i=0;i<N;i++){
    int sa=0;
    sa=A*1000-(T*1000-H.at(i)*6);
    if(sa<0){ sa = sa*(-1);}
    
    if(sa<gosa){
      gosa = sa;
      chiten = i+1;
    }
  }
  
  cout << chiten << endl;
  
}