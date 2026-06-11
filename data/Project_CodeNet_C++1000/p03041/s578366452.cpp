#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N, K;
  cin >> N >> K;
  char S[N];
  cin >> S;
  for(int i = 0; i < N; i++){
    if(i == K - 1)
      S[i] = S[i] + 32;
  }
  printf("%s\n",S);
  return 0;
}
