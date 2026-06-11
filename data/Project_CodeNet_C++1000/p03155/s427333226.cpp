#include <iostream>

int main(){
	
	int N,H,W;
	std::cin>>N>>H>>W;
	std::cout<<(N-W+1)*(N-H+1)<<std::endl;
	
	return 0;
}
