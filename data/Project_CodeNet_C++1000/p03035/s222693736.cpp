#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;
void tolow(char *a);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int age,price;
  cin>>age>>price;
  if(age>=13)
    cout<<price<<'\n';
  else if(age>5 && age<13)
    cout<<price/2<<'\n';
  else
    cout<<"0\n";
}
