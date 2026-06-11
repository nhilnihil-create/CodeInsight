#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits>

int main(){
  	int n,h;
  	std::cin>>n>>h;
  	std::vector<std::pair<int,int>> damages(n);
  	int Ma=-1;
  	int num_throw=0;
  	for(auto&damage : damages){
      	std::cin >> damage.first >> damage.second;
      	Ma = std::max(damage.first, Ma);
    }
  	std::sort(damages.begin(),damages.end(),[](auto &&a, auto&&b)->bool{ return a.second > b.second; });
  	for(auto&damage : damages){
      	if(damage.second > Ma){
          	num_throw++;
          	h-=damage.second;
          	if(h <= 0){ std::cout << num_throw << "\n"; return 0;}
        }
    }
  	std::cout << num_throw + int(h/Ma) + ((h%Ma>0)? 1: 0) << "\n";
  	return 0;
}