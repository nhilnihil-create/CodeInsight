#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  string W[N];
  for (int i = 0; i < N; i++){
    cin >> W[i];
  }

  int flg = 0;
  for (int i = 1; i < N; i++){
    if(W[i-1].back() != W[i].front()) flg = 1;
  }
  
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      if (i != j && W[i] == W[j]) flg = 1;
    }
  }
  
  if (flg==0){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
}
