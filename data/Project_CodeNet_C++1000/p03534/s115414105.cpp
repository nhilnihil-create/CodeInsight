#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#include <set>
int main(){
	std::string S;
	std::cin >> S;
	std::vector<int> count(3);
	count[0]=count[1]=count[2]=0;

	for(int i=0;i<S.size();i++){
		if(S[i]=='a'){
			count[0]++;
		}else if(S[i]=='b'){
			count[1]++;
		}else{
			count[2]++;
		}
	}
	std::sort(count.begin(),count.end());
	if(count[0]==count[1]&&count[1]==count[2]){
		std::cout <<"YES" <<std::endl;
	}else if(count[0]==count[1]&&count[2]==count[0]+1){
		std::cout <<"YES" <<std::endl;
	}else if(count[1]==count[2]&&count[0]==count[1]-1){
		std::cout <<"YES" <<std::endl;
	}else{
		std::cout << "NO" <<std::endl;
	}
}