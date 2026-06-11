#include<iostream>
#include<string>
int main(){
	std::string S;
  	int counter=0;
  	std::cin>>S;
  	if(S[0]=='o')++counter;
  	if(S[1]=='o')++counter;
  	if(S[2]=='o')++counter;
  	std::cout<<(700+counter*100);
  
  
}
