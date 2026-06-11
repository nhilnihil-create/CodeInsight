#include<iostream>
#include<vector> 
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
  long long A, B;	cin >> A >> B;
  if(A%B==0)	cout << -1;
  else	cout << A;
}