#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  N = 5;

  vector<int> vec(N);

  for (int i = 0; i < N; i++)
  {
    cin >> vec.at(i);
  }
  int time = 0;
  int tmp;
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      if (vec.at(i) % 10 < vec.at(j) % 10){
        tmp = vec.at(j);
        vec.at(j) = vec.at(i);
        vec.at(i) = tmp;
      }
    }    
  }
  
  int cnt = 0;
  for (int i = N - 1; i > -1; i--){
    if (vec.at(i) % 10 == 0){
      time += vec.at(i);
      cnt += 1;
    }
  }

  for (int i = 0; i < N - cnt; i++)
  {
    if (i == N - 1 - cnt){
      time += vec.at(i);
    }
    else
    {
      time += vec.at(i);
      time += 10 - vec.at(i) % 10;
    }
    
  }
  
  cout << time << endl;
}