#include<iostream>
using namespace std;
int main(){
  int N;
  cin >> N;
  for(int i=N; i<=999; i++){
    if(i%10 == i/100 && i%10 == (i/10)%10){
      cout << i;
      return 0;
    }
  }
}