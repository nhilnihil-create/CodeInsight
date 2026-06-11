#include<iostream>
using namespace std;

int main(){
  int N;  cin >> N;
  int ans = 0;
  for(int i=1;i<=N;i = i+2){
    int count = 0;
    for(int j=1;j*j<=i;j++){
      if(i%j == 0){
        if(i/j == j)  count++;
        else  count += 2;
      }
    }
    if(count == 8){
      ans++;
    }
  }
  cout << ans << endl;
}