#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  
  int countshou=0;
  int countdai=0;
  
  vector<int> a(M);
  for(int i=0;i<M;i++){
    cin >> a.at(i);
    if(a.at(i)<X){countshou++;}
    else if(a.at(i)>X){countdai++;}
  }
  
  cout << min(countshou,countdai) << endl;
    
          
}