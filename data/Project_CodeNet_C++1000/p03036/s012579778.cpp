#include<iostream>
using namespace std;
 
int main(){
  int r, d, x, ans[100];
  cin >> r >> d >> x;
  for(int i = 0;i < 10;i++){
    if(i == 0){
    ans[0] = x * r - d;
    }
    else{
      ans[i] = ans[i - 1] * r - d;
    }
    cout << ans[i] <<endl;
  }
}