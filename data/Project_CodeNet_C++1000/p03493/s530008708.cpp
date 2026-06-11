#include<bits/stdc++.h>
using namespace std;

int main()
{
  int count=0;
  string numbers;
  cin >> numbers;
  for(int i=0; i < numbers.length(); i++)
  {
    if(numbers[i] == '1')
    {
      count += 1;
    }
  }
  cout << count << endl;
}
