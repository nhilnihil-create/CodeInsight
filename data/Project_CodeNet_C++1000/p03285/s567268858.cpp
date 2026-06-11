#include<iostream>
#include<string>
#define rep(i, n) for (int i = 0; i < (n); i ++)

using namespace std;

int main()
{
  const int cake = 4;
  const int donut = 7;
  
  int x;
  cin >> x;
  
  if (x < cake)
  {
    cout << "No";
    return 0;
  }

  int max_cake = x / cake;
  int max_donut = x / donut;
  
  rep(i, max_cake + 1)
  {
    rep(j, max_donut + 1)
    {
      if (i * cake + j * donut == x)
      {
        cout << "Yes";
        return 0;
      }
    }
  }
  
  cout << "No";
  return 0;
}
