#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

// int max: 2 x 10^9, long long max: 9 x 10^18

using namespace std;

int main()
{
  long long r, d, x;
  cin >> r >> d >> x;
  
  vector<long long> result(10);
  result[0] = r * x - d;
  cout << result[0] << endl;
  for(int i=1; i<10; i++){
    result[i] = r * result[i-1] - d;
    cout << result[i] << endl;
  }

  return 0;
}