#include<bits/stdc++.h>
using namespace std;
 
bitset<2000007> dp; 
int main()
{
	int n;
  cin >> n;
  dp[0] = 1;
  int x = 0;
  int sum = 0;
  for(int i = 0 ; i  < n ;i++)
  {
    cin >> x;
    sum = sum + x;
    dp = (dp | dp << x);
  }
  int target = ( sum + 1 )/2;
  
  for(int i = target; i<= sum ;i++)
  {
  	if(dp[i])
    {
    	cout << i;
      break;
    }
  }
  
	return 0;
}