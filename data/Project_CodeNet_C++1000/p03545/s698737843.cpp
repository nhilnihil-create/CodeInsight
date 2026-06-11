#include <bits/stdc++.h>
using namespace std;

int keisan(int ABCD, string op)
{
  vector<int> a(4);
  a.at(3) = ABCD%10;
  a.at(2) = (ABCD/10)%10;
  a.at(1) = (ABCD/100)%10;
  a.at(0) = ABCD/1000;
  
  int ans = a.at(0);
  
  for(int i=1; i<4; i++)
  {
    if(op.at(i-1) == '+')
    {
      ans += a.at(i);
    }
    else
    {
      ans -= a.at(i);
    }
  }
  
  return ans;
}
  
int main()
{
  int ABCD;
  cin >> ABCD;
  vector<int> a(4);
  a.at(3) = ABCD%10;
  a.at(2) = (ABCD/10)%10;
  a.at(1) = (ABCD/100)%10;
  a.at(0) = ABCD/1000;
  string tes = "+-";
  string op = "+++";
  
  for(int i=0; i<2; i++)
  {
    for(int j=0; j<2; j++)
    {
      for(int k=0; k<2; k++)
      {
        op.at(0) = tes.at(i);
        op.at(1) = tes.at(j);
        op.at(2) = tes.at(k);
        if(keisan(ABCD,op) == 7) break;
      }
      if(keisan(ABCD,op) == 7) break;
    }
    if(keisan(ABCD,op) == 7) break;
  }
  
  cout << a.at(0);
  for(int i=0; i<3; i++)
  {
    cout << op.at(i) << a.at(i+1);
  }
  
  cout << "=7" << endl;
  
}
  
    
  
  
  
  
  