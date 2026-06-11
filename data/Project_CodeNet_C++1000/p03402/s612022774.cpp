#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
  int a,b,i,j;
  char ans[110][110];
  cin >> a >> b;
  for (i=0;i<50;i++) for (j=0;j<100;j++) ans[i][j]='#';
  for (i=50;i<100;i++) for (j=0;j<100;j++) ans[i][j]='.';
  for (i=0;i<50 && a>1;i+=2) for (j=0;j<100 && a>1;j+=2){
    ans[i][j]='.';
    a--;
  }
  for (i=51;i<100 && b>1;i+=2) for (j=0;j<100 && b>1;j+=2){
    ans[i][j]='#';
    b--;
  }
  for (i=0;i<100;i++) ans[i][100]='\0';
  cout << "100 100" << endl;
  for (i=0;i<100;i++) cout << ans[i] << endl;
  return 0;
}