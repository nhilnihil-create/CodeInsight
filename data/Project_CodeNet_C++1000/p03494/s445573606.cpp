#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  int min;
  int input;
  bool flag=false;
  cin >> N;
  
  for(int i=0; i<N; i++)
  {
    cin >> input;
    if(input % 2 == 0)
    {
      	int cnt = 0;
    	while(true)
    	{
          if(input % 2 != 0)
          {
            break;
          }
          cnt += 1;
          input /= 2;
    	}
      	if(min > cnt || i == 0)
        {
          min = cnt;
        }
    }
    else
    {
      flag = true;
    }
  }
  if(flag)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << min << endl;
  }
}
