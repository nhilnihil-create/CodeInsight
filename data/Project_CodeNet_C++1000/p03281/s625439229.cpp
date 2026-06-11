#include <bits/stdc++.h>
using namespace std;

int yakusuu(int n){
  int count = 0;
  for(int i=1;i<=n;i++){
    if(n%i == 0){
      count++;
    }
  }
  return count;
}
int main() {
  int N;
  cin >> N;
  int count = 0;
  for(int i=1;i<=N;i++){
    if(yakusuu(i) == 8 && i%2 == 1){
      count++;
    }
  }
  cout << count << endl;
}