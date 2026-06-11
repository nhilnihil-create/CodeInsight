#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
int main(){
  int N;
  cin >> N;
  int pos[3][N+1];
  for (int i=1;i<=N;i++){
    cin >> pos[0][i] >> pos[1][i] >> pos[2][i];
  }

  pos[0][0]=0;
  pos[1][0]=0;
  pos[2][0]=0;
  int n,flag=0;
  for (int i=1 ;i<=N;i++){
    n= (pos[0][i]-pos[0][i-1])-abs(pos[1][i]-pos[1][i-1])-abs(pos[2][i]-pos[2][i-1]);
    if (abs(n)%2==1||n<0){
      flag=1;
      cout << "No" << endl;
      break;
    }

  }
  if (flag==0){
    cout << "Yes" << endl;
  }

}
