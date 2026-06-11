#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

typedef pair<int,int> pii;

int n,m;
int li[N+5];

vector<pii> com;

int main(){
	scanf("%d",&n);
	int maksi,mini;
	maksi = mini = 1;
	for(int i=1;i<=n;i++){
		scanf("%d",&li[i]);
		if(li[i] > li[maksi]) maksi = i;
		if(li[i] < li[mini]) mini = i;
	}
	if(-li[mini] > li[maksi]){
		for(int i=1;i<=n;i++){
			if(li[i] > 0){
				com.push_back(make_pair(mini,i));
				li[i] += li[mini];
			}
		}
		
		for(int i=n-1;i>=1;i--){
			com.push_back(make_pair(i+1,i));
		}
	} else {
		for(int i=1;i<=n;i++){
			if(li[i] < 0){
				com.push_back(make_pair(maksi,i));
				li[i] += li[mini];
			}
		}
		
		for(int i=2;i<=n;i++){
			com.push_back(make_pair(i-1,i));
		}
	}
	printf("%d\n",com.size());
	for(int i=0;i<com.size();i++){
		printf("%d %d\n",com[i].first,com[i].second);
	}
	return 0;
}