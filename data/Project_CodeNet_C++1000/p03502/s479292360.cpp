#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int sum, i;
    string N;
  
	i = 0;
    sum = 0;
    cin >> N;
    while (N[i] != '\0')
    {
      sum += N[i] - 48;
      ++i;
    }
	int change = stoi(N); 
    if (change % sum == 0)
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
    return (0);
}