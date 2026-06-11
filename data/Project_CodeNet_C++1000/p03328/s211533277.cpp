#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int a,b;
  cin >> a >> b;
  
  int sta = b - a;
  int sum = 0;
  for(int i = 1; i <= sta; i++){
    sum += i;
  }
  
  cout << sum - b << endl;
}