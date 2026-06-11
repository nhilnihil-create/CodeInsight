#include <iostream>
using namespace std;

int main()
{
 	char c1[3];
  	char c2[3];
  	cin >> c1;
  	cin >> c2;
  	if(c1[0] != c2[2])
      cout << "NO";
  	else if(c1[1] != c2[1])
      cout << "NO";
  	else if(c1[2] != c2[0])
      cout << "NO";
  	else
      cout << "YES";
}