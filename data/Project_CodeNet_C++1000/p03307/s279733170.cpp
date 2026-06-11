#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  for(int i=1;;i++){
    int x=N*i;
    if(x%2==0){
      cout << x << endl;
      return 0;
    }
  }
  return 0;
}
