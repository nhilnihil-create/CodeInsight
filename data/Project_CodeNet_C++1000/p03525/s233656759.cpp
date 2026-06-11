#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>
#include <fstream>

const long INF = (1l << 30);
const long LINF = (1l << 60);

typedef std::pair<long, std::vector<long> > P;
typedef std::pair<long, std::pair<long, std::vector<long> > > PP;

long n;
long d[50];



int main(){
	scanf("%ld", &n);
	for(int i = 0; i < n; i++){
		scanf("%ld", d+i);
	}
	std::priority_queue<PP> que;
	std::vector<long> v;
	v.push_back(0);
	que.push(PP(LINF, P(1l, v)));
	
	while(true){
		
		/*
		printf("que.size() = %ld\n", que.size());
		std::priority_queue<PP> que2;
		while(!que.empty()){
			PP out = que.top();
			que.pop();
			printf("  (%ld, (%ld, (", out.first, out.second.first);
			for(int i = 0; i < out.second.first; i++){
				printf("%ld ", out.second.second.at(i));
			}
			printf(")))\n");
			que2.push(out);
		}
		que.swap(que2);
		//*/
		
		PP vis = que.top();
		que.pop();
		long length = vis.second.first;
		
		/*
		printf("  (%ld, (%ld, (", vis.first, length);
		for(int i = 0; i < length; i++){
			printf("%ld ", vis.second.second.at(i));
		}
		printf(")))\n");
		//*/
		
		if(length == n+1){
			printf("%ld\n", vis.first);
			return 0;
		}
		
		//printf("    positive part\n");
		long posRes = vis.first;
		std::vector<long> posVec = vis.second.second;
		posVec.push_back(d[length-1]);
		for(int i = 0; i < length; i++){
			long d_i = std::abs(vis.second.second.at(i) - d[length-1]);
			posRes = std::min(posRes, std::min(d_i, 24-d_i));
		}
		que.push(PP(posRes, P(length+1, posVec)));
		
		//printf("    negative part\n");
		long negRes = vis.first;
		std::vector<long> negVec = vis.second.second;
		negVec.push_back(24-d[length-1]);
		for(int i = 0; i < length; i++){
			long d_i = std::abs(vis.second.second[i] - (24-d[length-1]));
			negRes = std::min(negRes, std::min(d_i, 24-d_i));
		}
		que.push(PP(negRes, P(length+1, negVec)));
	}
}
