#include<iostream>
using namespace std;

int main()
{
  int k;
  cin >> k;
  
  int odd = k / 2;
  if (k % 2 != 0) odd ++;
  
  int even = k / 2;
  
  cout << odd * even << endl;
  
  return 0;
}

// [1, k]の中の奇数と偶数１個ずつの組み合わせの数=奇数の個数*偶数の個数