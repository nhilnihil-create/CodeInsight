#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int cnt=0;
  bool flag=true;
  vector<int> num(n);
  
  for(int i=0; i<n; i++)
  {
    int tmp;
    cin >> num.at(i);
    
    
    if(num.at(i) % 2 != 0 || num.at(i) == 0)
    {
      flag = false;
      break;
    }
  }
  
  if(flag)
  {
    while(flag)
    {
      for(int i=0; i<n; i++)
      {
        num.at(i) /= 2;
        
        if (num.at(i) % 2 != 0)
        {
          flag = false;
          break;
        }
      }
      cnt++;
    }
  }
  
  if(cnt < 0) cnt = 0;
  cout << cnt << endl;
}