#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> piipi;

int n;

bool cek_bit(int id, int mask){
	return (1<<id) & mask;
}

int cnt_bit(int x){
	int ret = 0;
	while(x > 0){
		ret++;
		x/=2;
	}
	return ret;
}

vector<piipi> li;

int main(){
//	for(int i=0;i<20;i++){
//		printf(">>> %d\n",(1<<i));
//	}
	scanf("%d",&n);
	n--;
	if(n==1){
		printf("2 2\n");
		printf("1 2 0\n");
		printf("1 2 1\n");
		return 0;
	}
	int pan = cnt_bit(n);
	printf("%d ",pan);
	for(int i=1;i<pan;i++){
		li.push_back(make_pair(make_pair(i,i+1),(1<<(pan-i-1))));
		li.push_back(make_pair(make_pair(i,i+1),0));
	}
	int cur = (1<<(pan-1));
	int idx = 2;
	for(int i=pan-2;i>=0;i--){
		if(cek_bit(i,n)){
			li.push_back(make_pair(make_pair(1,min(pan,idx)),cur));
			cur+=(1<<i);
		}
		idx++;
	}
	li.push_back(make_pair(make_pair(1,pan),cur));
	printf("%d\n",li.size());
	for(int i=0;i<li.size();i++){
		printf("%d %d %d\n",li[i].first.first,li[i].first.second,li[i].second);
	}
	return 0;
}

/*

10010101


 
*/