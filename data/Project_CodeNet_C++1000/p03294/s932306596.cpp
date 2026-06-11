#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

#define DEBUG if(false)

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  int sum = 0;
  for(int i = 0; i < N; i++){
    cin >> a[i];
    sum += a[i] -1;
  }

  cout << sum;

  return 0;
}
