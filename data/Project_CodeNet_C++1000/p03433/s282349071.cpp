#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n, a;
  cin >> n >> a;
  int money = n % 500;
  if (money > a){
    cout << "No" << endl;

  }
  else{
    cout << "Yes" << endl;
  }
}
