#include<iostream>
#include <string>
using namespace std;
int main()
{
	int a, b, p;
  	string s;
  	cin >> a >> b;
  	p = a*b;
	if (p%2 == 0){
      s = "Even";
    }else {
      s = "Odd";
    }
  	cout << s << endl;
    return 0;
}