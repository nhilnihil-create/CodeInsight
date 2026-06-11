#include <iostream>
#include <string>
using namespace std;

int main()
{
  	string X,Y;
  	string s[6] = {"A","B","C","D","E","F"};
  	int x,y;
  	cin >> X;
  	cin >> Y;
  
  	if(X == Y)
      cout << "=";
  
  	for(int i = 0;i <6;i++){
      if(s[i] == X)
        x = i + 10;}
  
  	for(int i = 0;i <6;i++){
      if(s[i] == Y)
        y = i + 10;}
  
  	if(x<y)
      cout << "<";
  	else if(x>y)
      cout << ">";
}