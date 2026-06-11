#include<bits/stdc++.h>
using namespace std;


int main(){
  int N,M,X,Y;
  cin >> N >> M >> X >> Y;

  vector<int> x(N);
  vector<int> y(M);

  for(int i = 0; i < N; i++){
    cin >> x[i];
  }
  int hantei;
  for(int i = 0; i < M; i++){
    cin >> y[i];
  }
for(int i = X + 1; i <= Y; i++){
  hantei = 1;
  for(int j = 0; j < N; j++){
    if(x[j] >= i){ hantei = 0; break;}
  }
    for(int k = 0; k < M; k++){
      if(y[k] < i){ hantei = 0; break; }
    }
   
    if(hantei == 1){ cout << "No War" << endl; return 0; }
  
}

cout << "War" << endl;
    return 0;

}