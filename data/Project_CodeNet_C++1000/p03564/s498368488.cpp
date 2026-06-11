#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  int N, K;
  cin >> N >> K;
  int num = 1;
  for(int i = 0; i < N; i++){
    if(num * 2 <= num + K){
      num = num * 2;
    }
    else num = num + K;
  }
  cout << num << endl;
}