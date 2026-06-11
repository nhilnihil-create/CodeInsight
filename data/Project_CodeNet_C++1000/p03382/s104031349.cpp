#include<iostream>
#include<vector>
#include<cmath>

int main(){
	int n;
	std::vector<int> cList;

	std::cin>>n;
	cList.resize(n);
	for(int i=0; i<n; i++)
		std::cin>>cList[i];

	int cMaxNum=-1;
	int cMaxIdx=-1;

	for(int i=0; i<n; i++)
		if(cMaxNum< cList[i])
			cMaxIdx=i, cMaxNum=cList[i];
	
	int dMaxNum=-1;
	int dMaxIdx=-1;

	for(int i=0; i<n; i++){
		if(i==cMaxIdx)
			continue;

		int dNum= std::min(cMaxNum-cList[i], cList[i]);
		if(dMaxNum< dNum)
			dMaxIdx=i, dMaxNum=dNum;
	}

	std::cout<<cList[cMaxIdx]<<" "<<cList[dMaxIdx]<<std::endl;

	return 0;
	
}