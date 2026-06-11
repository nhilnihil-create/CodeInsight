#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

// int max: 2 x 10^9, long long max: 9 x 10^18

using namespace std;

int main()
{

  int a, b;
  cin >> a >> b;

  if(a <= 5){
    cout << 0;
  }else if (5 < a && a <= 12){
    cout << b/2;
  }else{
    cout <<b;
  }

  return 0;
}