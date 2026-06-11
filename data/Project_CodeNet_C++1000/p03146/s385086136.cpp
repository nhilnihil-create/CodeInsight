#include <iostream>
#include <set>
using namespace std;

int main()
{
  int s;
  cin >> s;
  set<int> st;
  st.insert(s);
  for(int i=0; i<1000000; i++)
  {
    if(s % 2 == 0)
      s /= 2;
    else
      s = 3 * s + 1;
    
    if(st.find(s) != st.end())
    {
      cout << i+2 << endl;
      return 0;
    }
    else
      st.insert(s);
  }
}