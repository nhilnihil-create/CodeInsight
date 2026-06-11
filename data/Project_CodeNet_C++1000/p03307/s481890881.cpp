#include <iostream>
#include <string>
#include <vector>

#include <climits>

#define DEBUG if(false)

using namespace std;

int main(){

  int N, ans;
  cin >> N;
  if(N % 2 == 0){
    ans = N;
  }else{
    ans = N*2;
  }
  cout << ans << endl;
  return 0;
}
