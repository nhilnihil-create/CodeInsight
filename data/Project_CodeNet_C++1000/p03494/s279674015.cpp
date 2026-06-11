#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int> number(N);
  for(int i = 0; i < N; i++){
    cin >> number.at(i);
  }

  bool flag = true;
  int count = 0;
  while(flag == true){
    for(int i = 0; i < N; i++){
      if(number.at(i) % 2 != 0){
        flag = false;
        break;
      }
      else{
        count++;
        number.at(i) /= 2;
      }
    }
  }

  cout << count / N << endl;
}
