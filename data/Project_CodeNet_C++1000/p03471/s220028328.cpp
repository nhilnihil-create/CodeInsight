#include <bits/stdc++.h>

using namespace std;

int main(){
  int N ,Y ;

  cin >> N >> Y ;

  int money = Y;
  int sum = N;
  int cnt = 0;

  for(int i = 0;i <= sum;  i++){
    for(int j = 0; j <= sum-i; j++){
      for(int k = 0; k <= sum-i-j ; k++){
        //cout << "test " << i << " " << j << " " << k << endl;
        if(i * 10000 + j * 5000 + k * 1000 == money && i + j + k == sum){

          cout << i << " " << j << " " << k << endl;
          cnt++;
          goto finish;
        }

      }

    }

  }
  finish :
  if(cnt == 0){
    cout << -1 << " " << -1 << " " << -1 << endl;

  }
}
