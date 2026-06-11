#include <cstdio>
#include <map>
using namespace std;
int main(){
  int N;
  scanf("%d", &N)+1;
  map<char, char> mcc;
  char tmp;
  for (int i = 0; i < N+1; i++) {
    scanf("%c", &tmp)+1;
    mcc[tmp]++;
  }

  if (mcc['R'] > mcc['B']) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}