#include <iostream>
#include <string>

using namespace std;

int main(){
  int N, w = 0, b = 0;
  string S;
  cin >> N >> S;

  for (int i = 0; i < N; i++){
    if (S[i] == '.') w++;
  }

  int ans = w;

  for (int i = 0; i < N; i++){
    if (S[i] == '.') w--;
    if (S[i] == '#') b++;
    ans = min(ans, w + b); 
  }
  

  printf("%d\n", ans);
  
}
