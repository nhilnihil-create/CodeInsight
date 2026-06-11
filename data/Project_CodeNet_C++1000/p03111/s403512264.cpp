#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
using namespace std;
int main(){
	int n,a,b,c;
	int l[8];
	cin>>n>>a>>b>>c;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	int mi=1e9+7;
	for(int i=0;i<(1<<(2*n));i++){
		int now=0;
		int hoge=i;
		vector<int> ans;
		while(hoge!=0){
			if(hoge==hoge%(1<<(2*(now+1)))){
				ans.push_back(hoge/(1<<(2*now)));
				break;
			}else if(hoge%(1<<(2*(now+1)))!=0){
				ans.push_back(hoge%(1<<(2*(now+1)))/(1<<(2*now)));
				hoge-=hoge%(1<<(2*(now+1)));
			}else{
				ans.push_back(0);
			}
			now++;
		}
		int ca=0,cb=0,cc=0;
		int la=0,lb=0,lc=0;
		for(int j=0;j<ans.size();j++){
			if(ans[j]==1){
				ca++;
				la+=l[j];
			}else if(ans[j]==2){
				cb++;
				lb+=l[j];
			}else if(ans[j]==3){
				cc++;
				lc+=l[j];
			}
		}
		if(la==0||lb==0||lc==0){
			continue;
		}
		if(la<lb){
			swap(la,lb);
		}
		if(lb<lc){
			swap(lb,lc);
		}
		if(la<lb){
			swap(la,lb);
		}
		int cost=0;
		if(ca!=0){
			cost+=(ca-1)*10;
		}
		if(cb!=0){
			cost+=(cb-1)*10;
		}
		if(cc!=0){
			cost+=(cc-1)*10;
		}
		cost+=abs(la-a);
		cost+=abs(lb-b);
		cost+=abs(lc-c);
		mi=min(mi,cost);
	}
	cout<<mi<<endl;
	return 0;
}
