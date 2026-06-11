#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
int main(void){
  int N;
  cin >> N;
  int a[110];
  for(int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N, greater<int>());
  int Alice = 0, Bob = 0;
  for(int i = 0; i < N; i++){
    if(i % 2 == 0){
      Alice += a[i];
    }
    else{
      Bob += a[i];
    }
  }
  cout << Alice - Bob << endl;
  return 0;
}