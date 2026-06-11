#include<iostream>
#include<vector>
#include<string>

int main(){
	std::string s;
	int x, y;
	std::vector<int> distXList;
	std::vector<int> distYList;

	std::vector<std::vector<bool>> dpTableX;
	std::vector<std::vector<bool>> dpTableY;

	bool isX= true;
	int distCount= 0;

	int distXsum=0;
	int distYsum=0;

	std::cin>> s;
	std::cin>> x>> y;

	for(int i=0; i<s.size(); i++){
		if(s[i]=='F')
			distCount++;
		
		if(s[i]=='T' || i==s.size()-1){
			if(isX){
				distXList.push_back(distCount);
				distXsum+= distCount;
			}
			else{
				distYList.push_back(distCount);
				distYsum+= distCount;
			}

			distCount=0;
			isX= !isX;
		}
	}

	dpTableX.resize(distXList.size());
	for(int i=0; i< distXList.size(); i++)
		dpTableX[i].resize(distXsum*2+ 1, false);
	
	dpTableY.resize(distYList.size());
	for(int i=0; i< distYList.size(); i++)
		dpTableY[i].resize(distYsum*2+ 1, false);

	if(!distXList.empty())
		dpTableX[0][distXsum+distXList[0]]=true;
	
	if(!distYList.empty()){
		dpTableY[0][distYsum+distYList[0]]=true;
		dpTableY[0][distYsum-distYList[0]]=true;
	}

	for(int i=1; i< distXList.size(); i++){
		for(int j=0; j<distXsum*2 +1; j++){
			if(dpTableX[i-1][j]==true){
				dpTableX[i][j+distXList[i]]=true;
				dpTableX[i][j-distXList[i]]=true;
			}
		}
	}

	for(int i=1; i< distYList.size(); i++){
		for(int j=0; j<distYsum*2 +1; j++){
			if(dpTableY[i-1][j]==true){
				dpTableY[i][j+distYList[i]]=true;
				dpTableY[i][j-distYList[i]]=true;
			}
		}	
	}

	if(dpTableY.empty()){
	if(dpTableX[distXList.size()-1][distXsum+x] && y==0)
		std::cout<<"Yes"<<std::endl;
	else
		std::cout<<"No"<<std::endl;

	return 0;

	}

	if(x>distXsum || x<-distXsum || y>distYsum || y<-distYsum){
		std::cout<<"No"<<std::endl;
		return 0;
	}


	if(dpTableX[distXList.size()-1][distXsum+x] && dpTableY[distYList.size()-1][distYsum+y])
		std::cout<<"Yes"<<std::endl;
	else
		std::cout<<"No"<<std::endl;

	return 0;
}