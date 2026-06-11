#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
  	int count = 0;
    for(int i = 0; i < 3; ++i)
    {
      if(num % 10 == 1) count++;
      num = num / 10;
    }
  
  	cout << count << endl;
}