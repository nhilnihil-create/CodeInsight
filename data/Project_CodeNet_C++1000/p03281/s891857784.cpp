#include<iostream>
using namespace std;
int main(void){
  int N;
  cin >> N;
  int count = 0;
  for (int i=1;i<=N;i+=2){
    int num = 0;
    for (int j=1;j<=i;j++){
      if((i%j) == 0) num++;
    }
    if (num == 8) count++;
  }
  cout << count << endl;
  return 0;
}