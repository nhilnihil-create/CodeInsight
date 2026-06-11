#include <iostream>
using namespace std;

int main()
{
  int trainCost, busCost, fare;
  fare = 0;

  cin >> trainCost >> busCost;
  fare = trainCost + (busCost / 2);
  cout << fare << endl;

}
