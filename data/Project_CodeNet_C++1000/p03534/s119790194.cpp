#include<iostream>
#include<vector>
#include<string>

int main(){
	std::string s;
	std::cin>>s;

	int numSet;
	std::vector<int> numChar(3, 0);

	for(int i=0; i< s.size(); i++)
		numChar[s[i]-'a']++;

	numSet= (s.size()-1)/3;



	for(int i=0; i<3; i++){
		if(numSet+1 < numChar[i]){
			std::cout<<"NO"<<std::endl;
			return 0;
		}
	}

	std::cout<<"YES"<<std::endl;

	return 0;
}