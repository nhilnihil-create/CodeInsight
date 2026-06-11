#include<iostream>
#include<string>
#include <numeric>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> P;
long long X, Y, cnt=1;

int main(){
  cin >> X >> Y;
  
  while(X<=Y){
    X = X*2;
    cnt++;
  }
  cout << cnt-1 << endl;
  return 0;
}