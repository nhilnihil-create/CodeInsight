#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
  string S;
  cin >> S;
  int n = S.size();
  int s[n];
  for (int i = 0; i < n; i++){
    s[i] = (int)(S[i] - '0');
  }

  int ans = 753;
  for (int i = 0; i < n - 2; i++){
    int num = s[i] * 100 + s[i+1] * 10 + s[i+2];
    if (ans > abs(753 - num)) {
      ans = abs(753 - num);
    }
  }
  
  printf("%d\n", ans);
  
}
