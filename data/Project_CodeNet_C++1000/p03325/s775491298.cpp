#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int count=0;
  for(int i=0 ; i<N ; i++){
    int a;
    cin >> a;
    while(a%2==0){
      count++;
      a>>=1;
    }
  }
  
  cout << count << endl;
  return 0;
}