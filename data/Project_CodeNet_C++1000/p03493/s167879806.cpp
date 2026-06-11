#include <iostream>

int main() {
	
   int count = 0;
   std::string s;
   std::cin >> s;
  
  	if(s[0] == '1') ++count;
	if(s[1] == '1') ++count;
	if(s[2] == '1') ++count;
  
  	std::cout <<  count << std::endl;
  
	return (0);

}