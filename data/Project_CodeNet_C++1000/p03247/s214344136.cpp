#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <unordered_map>
#include <set>
#include <string>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <queue>

#define N 1009

using namespace std;

pair<int,int> p[N];
vector<int> dis;

int main(){
	int i,j,t1,t2,t3,t4,n,par;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&t1,&t2);
		p[i]=make_pair(t1,t2);
	}	
	par=abs((p[0].first+p[0].second)%2);
	for(i=1;i<n;i++){
		t1=abs((p[i].first+p[i].second)%2);
		if(t1!=par){
			printf("-1\n");
			return 0;
		}
	}
	if(!par){
		dis.push_back(1);
	}
	for(i=0;i<31;i++){
		dis.push_back(1<<i);
	}
	reverse(dis.begin(),dis.end());
	printf("%d\n",(int)dis.size());
	for(auto it : dis){
		printf("%d ",it);
	}
	printf("\n");
	for(i=0;i<n;i++){
		t1=p[i].first;
		t2=p[i].second;
		for(j=0;j<(int)dis.size();j++){
			if(abs(t1)>abs(t2)){
				if(t1<0){
					printf("L");
					t1+=dis[j];
				}
				else{
					printf("R");
					t1-=dis[j];
				}
			}
			else{
				if(t2<0){
					printf("D");
					t2+=dis[j];
				}
				else{
					printf("U");
					t2-=dis[j];
				}
			}
		}
		printf("\n");
	}
    return 0;
}