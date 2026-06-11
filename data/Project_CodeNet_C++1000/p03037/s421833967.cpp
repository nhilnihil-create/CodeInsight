#include<iostream>

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  int L=0, R=N+1;
  for (int i = 0; i < M; i++){
    int Li, Ri;
    cin >> Li >> Ri;
    if(Li > L) L = Li;
    if(Ri < R) R = Ri;
  }

  if(L <= R){
    printf("%d\n", R - L + 1);
  }else
  {
    printf("0\n");
  }
  
  
}
