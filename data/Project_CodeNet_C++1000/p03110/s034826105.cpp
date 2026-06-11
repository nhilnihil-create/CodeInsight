#include <iostream>
#include <string>
using namespace std;

int main(){
  int N;
  string format;
  double money, sum = 0.0;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> money >> format;
    if (format == "JPY") sum += money;
    else sum += money * 380000.0;
  }
  cout << sum;
}