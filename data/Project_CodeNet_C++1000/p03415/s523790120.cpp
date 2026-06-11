#include<bits/stdc++.h>
using namespace std;

int main(void){
  char c[3][3];
  char s[3] = {'\0'};
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      cin >> c[i][j];
  for(int i = 0; i < 3; i++)
    s[i] += c[i][i];
  printf("%s\n", s);
  return 0;
}
