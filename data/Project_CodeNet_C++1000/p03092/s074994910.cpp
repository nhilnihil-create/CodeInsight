#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, leftMoveCost, rightMoveCost; std::cin>>number>>rightMoveCost>>leftMoveCost;
	std::vector<int> data(number), pos(number);
	for(int index=0;index<number;++index) {
		auto& item=data[index];
		std::cin>>item;--item; 
		pos[item]=index;
	}

	std::vector<std::vector<int64_t>> f(number+1, std::vector<int64_t>(number+1, INT64_MAX));
	f[0][0]=0;

	// f[a][b]=minimum cost to move a smallest numbers to the left, and
	// b numbers at first indices(including those that may be moved to the left)
	// to an arbitrary position to the right)
	for(int a=0;a<number;++a) {
		std::vector<int> uncoveredSuffix(number+1);
		for(int cur=0,index=number; index--;){
			uncoveredSuffix[index]=cur+=(data[index]>=a);
		}


		for(int b=0;b<=number;++b) if(f[a][b]!=INT64_MAX) {
			auto const cur=f[a][b];
			f[a+1][b]=std::min(f[a+1][b], cur+leftMoveCost);
			auto const rightMoveCount=std::max(0,uncoveredSuffix[b]-uncoveredSuffix[pos[a]]);
			auto& next2=f[a+1][std::max(b, pos[a]+1)];
			next2=std::min(next2, cur+(int64_t)rightMoveCost*rightMoveCount);
		}
	}

	std::cout<<*std::min_element(begin(f[number]),end(f[number]))<<'\n';
}
