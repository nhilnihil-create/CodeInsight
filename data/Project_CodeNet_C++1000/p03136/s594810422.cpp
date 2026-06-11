#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

int n,max=0,sum=0;
cin >> n;
int arr;

while(n-->0)
{
  cin >> arr;
  sum+=arr;
  
  if(arr>max)
  {
	  max=arr;
  }
}

if(max< (sum-max))
{
	 cout << "Yes" << endl;
}
else
{
	cout << "No" << endl;
}
	return 0;
}









