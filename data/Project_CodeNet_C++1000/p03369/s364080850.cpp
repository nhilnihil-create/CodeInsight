#include <bits/stdc++.h>
using namespace std;


int main()
{
  string s;
  cin >> s;
  int count = 0;
  for (int i = 0; i < 3; i++)
  {
    if(s.at(i) == 'o'){
      ++count;
    }
  }
  int price;
  if (count > 0)
  {
     price = 700 + (count * 100);
  }else if(count == 0){
    price = 700;
  }

  cout << price << endl;
}
