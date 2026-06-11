#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[10] = {};
  
  for (int i = 0;i < 4; i++)
  {
   	char c;
    cin >> c;
    arr[c-'0']++;
  }
  
  if (arr[1]%2 && arr[4]%2 && arr[7]%2 && arr[9]%2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}