#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  int ex , val;
  cin >> ex >> val;
  if(ex==0)
  {
      if(val==100)cout << 101 << endl;
      else
      cout << val << endl;

  }
  else if(ex==1)
  {
      if(val==100)cout << 101*100 ;
      else
      cout << val*100;
    cout << endl;
  }
  else {
        if(val==100)
        cout << 101*10000 << endl;
  else
        cout << val*10000 << endl;}

    }
