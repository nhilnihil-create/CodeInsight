#include <iostream>
using namespace std;

int main() {
 int s,b,c;
 cin>>s>>b;

  if(s==b)
	  cout<<s*2;

  else{
	  c=max(s,b);
	  cout<<c+c-1;}

	return 0;
}
